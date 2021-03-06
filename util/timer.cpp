#include "timer.hpp"

namespace chr {

chr_timer_t::chr_timer_t(uint32_t interval_ms, timer_callback_t &cb)
{
    m_trigger = channel_t<int>::create();
    m_cb = std::move(cb);
    m_interval_ms = interval_ms;
}

chr_timer_t::~chr_timer_t()
{
}


int chr_timer_t::select(int wait_ms)
{
    if (!m_running) {
        return 0;
    }
    
    // @wait_ms will be ignored, as 0
    return m_selecter.select_once();
}

bool chr_timer_t::start(bool once)
{
    if (m_running) {
		SPDLOG(ERROR, "chr_timer_t::start ignored: already running");
        return false;
    }

    if (m_cb == nullptr || m_interval_ms == 0) {
		SPDLOG(ERROR, "chr_timer_t::start error: m_cb == nullptr || m_interval_ms == 0");
        return false;
    }

    m_running = true;
    m_once = once;
    // start the trigger chroutine
    m_trigger_chroutine_id = ENGIN.create_son_chroutine([&](void *){
        SLEEP(m_interval_ms);
        while (m_running) {
            *m_trigger << 1;
            SLEEP(m_interval_ms);
        }
        m_trigger_chroutine_id = INVALID_ID;
    }, nullptr);

    // add select case
    m_selecter.add_case(m_trigger.get(), &m_d, [&](){
        if (!m_running) {
            return;
        }
        ENGIN.create_son_chroutine([&](void *){
            if (m_cb != nullptr) m_cb();
            if (m_once) stop();
        }, nullptr);
    });

    return true;
}

void chr_timer_t::stop()
{
    if (!m_running) {
		SPDLOG(ERROR, "chr_timer_t::stop ignored: not running");
        return;
    }

	SPDLOG(DEBUG, "timer:{:p} stopping ...", (void*)this);
    m_running = false;
    m_selecter.select_once();   //clear the channel buf
    m_selecter.del_case(m_trigger.get());

    //wake up and go die!
    if (m_trigger_chroutine_id != INVALID_ID) {
        ENGIN.awake_chroutine(m_trigger_chroutine_id);  
    }

    // wait till triggle chroutine finished
    while (m_trigger_chroutine_id != INVALID_ID) {
        SLEEP(5);
    }
	SPDLOG(DEBUG, "timer:{:p} stopped!", (void*)this); 
}

void chr_timer_t::abandon() 
{
    if (m_running) {
	    SPDLOG(DEBUG, "chr_timer_t::abandon: timer({:p}) is running, stop it!", (void*)this);
        stop();
    }
    unregister_from_engin();
}

}