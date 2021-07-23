
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-FAKE-NON-IVI Metadata
//---------------------------------------------------------------------
#include "nifake_non_ivi_service.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>
#include "custom/nidaqmx_conversions.h"

namespace nifake_non_ivi_grpc {

  NiFakeNonIviService::NiFakeNonIviService(NiFakeNonIviLibraryInterface* library, ResourceRepositorySharedPtr session_repository)
      : library_(library), session_repository_(session_repository)
  {
  }

  NiFakeNonIviService::~NiFakeNonIviService()
  {
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_grpc_session = request->handle();
      FakeHandle handle = session_repository_->access_session(handle_grpc_session.id(), handle_grpc_session.name());
      session_repository_->remove_session(handle);
      auto status = library_->Close(handle);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::Init(::grpc::ServerContext* context, const InitRequest* request, InitResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_name = request->session_name().c_str();

      auto init_lambda = [&] () {
        FakeHandle handle;
        int status = library_->Init(session_name, &handle);
        return std::make_tuple(status, handle);
      };
      uint32_t session_id = 0;
      const std::string& grpc_device_session_name = request->session_name();
      auto cleanup_lambda = [&] (FakeHandle id) { library_->Close(id); };
      int status = session_repository_->add_session(grpc_device_session_name, init_lambda, cleanup_lambda, session_id);
      response->set_status(status);
      if (status == 0) {
        response->mutable_handle()->set_id(session_id);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::InitWithHandleNameAsSessionName(::grpc::ServerContext* context, const InitWithHandleNameAsSessionNameRequest* request, InitWithHandleNameAsSessionNameResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto handle_name = request->handle_name().c_str();

      auto init_lambda = [&] () {
        FakeHandle handle;
        int status = library_->InitWithHandleNameAsSessionName(handle_name, &handle);
        return std::make_tuple(status, handle);
      };
      uint32_t session_id = 0;
      const std::string& grpc_device_session_name = request->handle_name();
      auto cleanup_lambda = [&] (FakeHandle id) { library_->Close(id); };
      int status = session_repository_->add_session(grpc_device_session_name, init_lambda, cleanup_lambda, session_id);
      response->set_status(status);
      if (status == 0) {
        response->mutable_handle()->set_id(session_id);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::InputArraysWithNarrowIntegerTypes(::grpc::ServerContext* context, const InputArraysWithNarrowIntegerTypesRequest* request, InputArraysWithNarrowIntegerTypesResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto u16_array_raw = request->u16_array();
      auto u16_array = std::vector<myUInt16>();
      u16_array.reserve(u16_array_raw.size());
      std::transform(
        u16_array_raw.begin(),
        u16_array_raw.end(),
        std::back_inserter(u16_array),
        [](auto x) { 
              if (x < std::numeric_limits<myUInt16>::min() || x > std::numeric_limits<myUInt16>::max()) {
                  std::string message("value ");
                  message.append(std::to_string(x));
                  message.append(" doesn't fit in datatype ");
                  message.append("myUInt16");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<myUInt16>(x);
        });

      auto i16_array_raw = request->i16_array();
      auto i16_array = std::vector<myInt16>();
      i16_array.reserve(i16_array_raw.size());
      std::transform(
        i16_array_raw.begin(),
        i16_array_raw.end(),
        std::back_inserter(i16_array),
        [](auto x) { 
              if (x < std::numeric_limits<myInt16>::min() || x > std::numeric_limits<myInt16>::max()) {
                  std::string message("value ");
                  message.append(std::to_string(x));
                  message.append(" doesn't fit in datatype ");
                  message.append("myInt16");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<myInt16>(x);
        });

      auto i8_array_raw = request->i8_array();
      auto i8_array = std::vector<myInt8>();
      i8_array.reserve(i8_array_raw.size());
      std::transform(
        i8_array_raw.begin(),
        i8_array_raw.end(),
        std::back_inserter(i8_array),
        [](auto x) { 
              if (x < std::numeric_limits<myInt8>::min() || x > std::numeric_limits<myInt8>::max()) {
                  std::string message("value ");
                  message.append(std::to_string(x));
                  message.append(" doesn't fit in datatype ");
                  message.append("myInt8");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<myInt8>(x);
        });

      auto status = library_->InputArraysWithNarrowIntegerTypes(u16_array.data(), i16_array.data(), i8_array.data());
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
    catch (nidevice_grpc::ValueOutOfRangeException& ex) {
      return ::grpc::Status(::grpc::OUT_OF_RANGE, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::IotaWithCustomSize(::grpc::ServerContext* context, const IotaWithCustomSizeRequest* request, IotaWithCustomSizeResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      int32 size_one = request->size_one();
      int32 size_two = request->size_two();
      response->mutable_data()->Resize((size_one < 0) ? size_two : size_one + 1, 0);
      int32* data = reinterpret_cast<int32*>(response->mutable_data()->mutable_data());
      auto status = library_->IotaWithCustomSize(size_one, size_two, data);
      response->set_status(status);
      if (status == 0) {
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::OutputArraysWithNarrowIntegerTypes(::grpc::ServerContext* context, const OutputArraysWithNarrowIntegerTypesRequest* request, OutputArraysWithNarrowIntegerTypesResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      int32 number_of_u16_samples = request->number_of_u16_samples();
      int32 number_of_i16_samples = request->number_of_i16_samples();
      int32 number_of_i8_samples = request->number_of_i8_samples();
      std::vector<myUInt16> u16_data(number_of_u16_samples);
      std::vector<myInt16> i16_data(number_of_i16_samples);
      std::vector<myInt8> i8_data(number_of_i8_samples);
      auto status = library_->OutputArraysWithNarrowIntegerTypes(number_of_u16_samples, u16_data.data(), number_of_i16_samples, i16_data.data(), number_of_i8_samples, i8_data.data());
      response->set_status(status);
      if (status == 0) {
        response->mutable_u16_data()->Clear();
        response->mutable_u16_data()->Reserve(number_of_u16_samples);
        std::transform(
          u16_data.begin(),
          u16_data.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_u16_data()),
          [](auto x) { 
              return x;
          });
        response->mutable_i16_data()->Clear();
        response->mutable_i16_data()->Reserve(number_of_i16_samples);
        std::transform(
          i16_data.begin(),
          i16_data.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_i16_data()),
          [](auto x) { 
              return x;
          });
        response->mutable_i8_data()->Clear();
        response->mutable_i8_data()->Reserve(number_of_i8_samples);
        std::transform(
          i8_data.begin(),
          i8_data.end(),
          google::protobuf::RepeatedFieldBackInserter(response->mutable_i8_data()),
          [](auto x) { 
              return x;
          });
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::InputArrayOfBytes(::grpc::ServerContext* context, const InputArrayOfBytesRequest* request, InputArrayOfBytesResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      const myUInt8* u8_array = (const myUInt8*)request->u8_array().c_str();
      auto status = library_->InputArrayOfBytes(u8_array);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::OutputArrayOfBytes(::grpc::ServerContext* context, const OutputArrayOfBytesRequest* request, OutputArrayOfBytesResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      int32 number_of_u8_samples = request->number_of_u8_samples();
      std::string u8_data(number_of_u8_samples, '\0');
      auto status = library_->OutputArrayOfBytes(number_of_u8_samples, (myUInt8*)u8_data.data());
      response->set_status(status);
      if (status == 0) {
        response->set_u8_data(u8_data);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::InputTimestamp(::grpc::ServerContext* context, const InputTimestampRequest* request, InputTimestampResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      CVIAbsoluteTime when = convert_from_grpc<CVIAbsoluteTime>(request->when());
      auto status = library_->InputTimestamp(when);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFakeNonIviService::OutputTimestamp(::grpc::ServerContext* context, const OutputTimestampRequest* request, OutputTimestampResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      CVIAbsoluteTime when {};
      auto status = library_->OutputTimestamp(&when);
      response->set_status(status);
      if (status == 0) {
        convert_to_grpc(when, response->mutable_when());
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

} // namespace nifake_non_ivi_grpc

