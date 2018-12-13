// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: test.proto
#ifndef GRPC_test_2eproto__INCLUDED
#define GRPC_test_2eproto__INCLUDED

#include "test.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc {
class CompletionQueue;
class Channel;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc

namespace rpcpb {

class Base final {
 public:
  static constexpr char const* service_full_name() {
    return "rpcpb.Base";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status Health(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::rpcpb::HealthRsp* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::rpcpb::HealthRsp>> AsyncHealth(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::rpcpb::HealthRsp>>(AsyncHealthRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::rpcpb::HealthRsp>> PrepareAsyncHealth(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::rpcpb::HealthRsp>>(PrepareAsyncHealthRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void Health(::grpc::ClientContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response, std::function<void(::grpc::Status)>) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::rpcpb::HealthRsp>* AsyncHealthRaw(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::rpcpb::HealthRsp>* PrepareAsyncHealthRaw(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status Health(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::rpcpb::HealthRsp* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::rpcpb::HealthRsp>> AsyncHealth(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::rpcpb::HealthRsp>>(AsyncHealthRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::rpcpb::HealthRsp>> PrepareAsyncHealth(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::rpcpb::HealthRsp>>(PrepareAsyncHealthRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void Health(::grpc::ClientContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response, std::function<void(::grpc::Status)>) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::rpcpb::HealthRsp>* AsyncHealthRaw(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::rpcpb::HealthRsp>* PrepareAsyncHealthRaw(::grpc::ClientContext* context, const ::rpcpb::HealthReq& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_Health_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status Health(::grpc::ServerContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_Health : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_Health() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_Health() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Health(::grpc::ServerContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestHealth(::grpc::ServerContext* context, ::rpcpb::HealthReq* request, ::grpc::ServerAsyncResponseWriter< ::rpcpb::HealthRsp>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_Health<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_Health : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_Health() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::rpcpb::HealthReq, ::rpcpb::HealthRsp>(
          [this](::grpc::ServerContext* context,
                 const ::rpcpb::HealthReq* request,
                 ::rpcpb::HealthRsp* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->Health(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithCallbackMethod_Health() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Health(::grpc::ServerContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Health(::grpc::ServerContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  typedef ExperimentalWithCallbackMethod_Health<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_Health : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_Health() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_Health() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Health(::grpc::ServerContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_Health : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_Health() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_Health() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Health(::grpc::ServerContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestHealth(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_Health : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_Health() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->Health(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_Health() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status Health(::grpc::ServerContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void Health(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_Health : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_Health() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::rpcpb::HealthReq, ::rpcpb::HealthRsp>(std::bind(&WithStreamedUnaryMethod_Health<BaseClass>::StreamedHealth, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_Health() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status Health(::grpc::ServerContext* context, const ::rpcpb::HealthReq* request, ::rpcpb::HealthRsp* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedHealth(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::rpcpb::HealthReq,::rpcpb::HealthRsp>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_Health<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_Health<Service > StreamedService;
};

}  // namespace rpcpb


#endif  // GRPC_test_2eproto__INCLUDED
