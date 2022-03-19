
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-FPGA Metadata
//---------------------------------------------------------------------
#include "nifpga_service.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>
#include <server/converters.h>

namespace nifpga_grpc {

  using nidevice_grpc::converters::calculate_linked_array_size;
  using nidevice_grpc::converters::convert_from_grpc;
  using nidevice_grpc::converters::convert_to_grpc;
  using nidevice_grpc::converters::MatchState;

  NiFpgaService::NiFpgaService(
      NiFpgaLibraryInterface* library,
      ResourceRepositorySharedPtr resource_repository,
      const NiFpgaFeatureToggles& feature_toggles)
      : library_(library),
      session_repository_(resource_repository),
      feature_toggles_(feature_toggles)
  {
  }

  NiFpgaService::~NiFpgaService()
  {
  }

  // Returns true if it's safe to use outputs of a method with the given status.
  inline bool status_ok(int32 status)
  {
    return status >= 0;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::Open(::grpc::ServerContext* context, const OpenRequest* request, OpenResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto bitfile = request->bitfile().c_str();
      auto signature = request->signature().c_str();
      auto resource = request->resource().c_str();
      uint32_t attribute;
      switch (request->attribute_enum_case()) {
        case nifpga_grpc::OpenRequest::AttributeEnumCase::kAttributeMapped: {
          auto attribute_imap_it = openattribute_input_map_.find(request->attribute_mapped());
          if (attribute_imap_it == openattribute_input_map_.end()) {
            return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute_mapped was not specified or out of range.");
          }
          attribute = static_cast<uint32_t>(attribute_imap_it->second);
          break;
        }
        case nifpga_grpc::OpenRequest::AttributeEnumCase::kAttributeRaw: {
          attribute = static_cast<uint32_t>(request->attribute_raw());
          break;
        }
        case nifpga_grpc::OpenRequest::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
        }
      }


      auto init_lambda = [&] () {
        NiFpga_Session session;
        auto status = library_->Open(bitfile, signature, resource, attribute, &session);
        return std::make_tuple(status, session);
      };
      uint32_t session_id = 0;
      const std::string& grpc_device_session_name = request->session_name();
      auto cleanup_lambda = [&] (NiFpga_Session id) { library_->Close(id, 1); };
      int status = session_repository_->add_session(grpc_device_session_name, init_lambda, cleanup_lambda, session_id);
      response->set_status(status);
      if (status_ok(status)) {
        response->mutable_session()->set_id(session_id);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::Close(::grpc::ServerContext* context, const CloseRequest* request, CloseResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t attribute;
      switch (request->attribute_enum_case()) {
        case nifpga_grpc::CloseRequest::AttributeEnumCase::kAttribute: {
          attribute = static_cast<uint32_t>(request->attribute());
          break;
        }
        case nifpga_grpc::CloseRequest::AttributeEnumCase::kAttributeRaw: {
          attribute = static_cast<uint32_t>(request->attribute_raw());
          break;
        }
        case nifpga_grpc::CloseRequest::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
        }
      }

      auto status = library_->Close(session, attribute);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::Run(::grpc::ServerContext* context, const RunRequest* request, RunResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t attribute;
      switch (request->attribute_enum_case()) {
        case nifpga_grpc::RunRequest::AttributeEnumCase::kAttribute: {
          attribute = static_cast<uint32_t>(request->attribute());
          break;
        }
        case nifpga_grpc::RunRequest::AttributeEnumCase::kAttributeRaw: {
          attribute = static_cast<uint32_t>(request->attribute_raw());
          break;
        }
        case nifpga_grpc::RunRequest::AttributeEnumCase::ATTRIBUTE_ENUM_NOT_SET: {
          return ::grpc::Status(::grpc::INVALID_ARGUMENT, "The value for attribute was not specified or out of range");
          break;
        }
      }

      auto status = library_->Run(session, attribute);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::Reset(::grpc::ServerContext* context, const ResetRequest* request, ResetResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      auto status = library_->Reset(session);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::Download(::grpc::ServerContext* context, const DownloadRequest* request, DownloadResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      auto status = library_->Download(session);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadBool(::grpc::ServerContext* context, const ReadBoolRequest* request, ReadBoolResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      NiFpga_Bool value {};
      auto status = library_->ReadBool(session, indicator, &value);
      response->set_status(status);
      if (status_ok(status)) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadI8(::grpc::ServerContext* context, const ReadI8Request* request, ReadI8Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      int8_t value {};
      auto status = library_->ReadI8(session, indicator, &value);
      response->set_status(status);
      if (status_ok(status)) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadU8(::grpc::ServerContext* context, const ReadU8Request* request, ReadU8Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      uint8_t value {};
      auto status = library_->ReadU8(session, indicator, &value);
      response->set_status(status);
      if (status_ok(status)) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadI16(::grpc::ServerContext* context, const ReadI16Request* request, ReadI16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      int16_t value {};
      auto status = library_->ReadI16(session, indicator, &value);
      response->set_status(status);
      if (status_ok(status)) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadU16(::grpc::ServerContext* context, const ReadU16Request* request, ReadU16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      uint16_t value {};
      auto status = library_->ReadU16(session, indicator, &value);
      response->set_status(status);
      if (status_ok(status)) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadI32(::grpc::ServerContext* context, const ReadI32Request* request, ReadI32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      int32_t value {};
      auto status = library_->ReadI32(session, indicator, &value);
      response->set_status(status);
      if (status_ok(status)) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadU32(::grpc::ServerContext* context, const ReadU32Request* request, ReadU32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      uint32_t value {};
      auto status = library_->ReadU32(session, indicator, &value);
      response->set_status(status);
      if (status_ok(status)) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadI64(::grpc::ServerContext* context, const ReadI64Request* request, ReadI64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      int64_t value {};
      auto status = library_->ReadI64(session, indicator, &value);
      response->set_status(status);
      if (status_ok(status)) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadU64(::grpc::ServerContext* context, const ReadU64Request* request, ReadU64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      uint64_t value {};
      auto status = library_->ReadU64(session, indicator, &value);
      response->set_status(status);
      if (status_ok(status)) {
        response->set_value(value);
      }
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteBool(::grpc::ServerContext* context, const WriteBoolRequest* request, WriteBoolResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      NiFpga_Bool value = request->value();
      auto status = library_->WriteBool(session, control, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteI8(::grpc::ServerContext* context, const WriteI8Request* request, WriteI8Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      int8_t value = request->value();
      auto status = library_->WriteI8(session, control, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteU8(::grpc::ServerContext* context, const WriteU8Request* request, WriteU8Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      uint8_t value = request->value();
      auto status = library_->WriteU8(session, control, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteI16(::grpc::ServerContext* context, const WriteI16Request* request, WriteI16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      int16_t value = request->value();
      auto status = library_->WriteI16(session, control, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteU16(::grpc::ServerContext* context, const WriteU16Request* request, WriteU16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      uint16_t value = request->value();
      auto status = library_->WriteU16(session, control, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteI32(::grpc::ServerContext* context, const WriteI32Request* request, WriteI32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      int32_t value = request->value();
      auto status = library_->WriteI32(session, control, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteU32(::grpc::ServerContext* context, const WriteU32Request* request, WriteU32Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      uint32_t value = request->value();
      auto status = library_->WriteU32(session, control, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteI64(::grpc::ServerContext* context, const WriteI64Request* request, WriteI64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      int64_t value = request->value();
      auto status = library_->WriteI64(session, control, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteU64(::grpc::ServerContext* context, const WriteU64Request* request, WriteU64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      uint64_t value = request->value();
      auto status = library_->WriteU64(session, control, value);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::ReadArrayI16(::grpc::ServerContext* context, const ReadArrayI16Request* request, ReadArrayI16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      size_t size = request->size();
      std::vector<int16_t> array(size);
      auto status = library_->ReadArrayI16(session, indicator, array.data(), size);
      response->set_status(status);
      if (status_ok(status)) {
        response->mutable_array()->Clear();
        response->mutable_array()->Reserve(size);
        std::transform(
          array.begin(),
          array.begin() + size,
          google::protobuf::RepeatedFieldBackInserter(response->mutable_array()),
          [&](auto x) {
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
  ::grpc::Status NiFpgaService::ReadArrayU16(::grpc::ServerContext* context, const ReadArrayU16Request* request, ReadArrayU16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      size_t size = request->size();
      std::vector<uint16_t> array(size);
      auto status = library_->ReadArrayU16(session, indicator, array.data(), size);
      response->set_status(status);
      if (status_ok(status)) {
        response->mutable_array()->Clear();
        response->mutable_array()->Reserve(size);
        std::transform(
          array.begin(),
          array.begin() + size,
          google::protobuf::RepeatedFieldBackInserter(response->mutable_array()),
          [&](auto x) {
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
  ::grpc::Status NiFpgaService::ReadArrayI64(::grpc::ServerContext* context, const ReadArrayI64Request* request, ReadArrayI64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      size_t size = request->size();
      std::vector<int64_t> array(size);
      auto status = library_->ReadArrayI64(session, indicator, array.data(), size);
      response->set_status(status);
      if (status_ok(status)) {
        response->mutable_array()->Clear();
        response->mutable_array()->Reserve(size);
        std::transform(
          array.begin(),
          array.begin() + size,
          google::protobuf::RepeatedFieldBackInserter(response->mutable_array()),
          [&](auto x) {
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
  ::grpc::Status NiFpgaService::ReadArrayU64(::grpc::ServerContext* context, const ReadArrayU64Request* request, ReadArrayU64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t indicator = request->indicator();
      size_t size = request->size();
      std::vector<uint64_t> array(size);
      auto status = library_->ReadArrayU64(session, indicator, array.data(), size);
      response->set_status(status);
      if (status_ok(status)) {
        response->mutable_array()->Clear();
        response->mutable_array()->Reserve(size);
        std::transform(
          array.begin(),
          array.begin() + size,
          google::protobuf::RepeatedFieldBackInserter(response->mutable_array()),
          [&](auto x) {
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
  ::grpc::Status NiFpgaService::WriteArrayI16(::grpc::ServerContext* context, const WriteArrayI16Request* request, WriteArrayI16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      auto array_raw = request->array();
      auto array = std::vector<int16_t>();
      array.reserve(array_raw.size());
      std::transform(
        array_raw.begin(),
        array_raw.end(),
        std::back_inserter(array),
        [](auto x) {
              if (x < std::numeric_limits<int16_t>::min() || x > std::numeric_limits<int16_t>::max()) {
                  std::string message("value ");
                  message.append(std::to_string(x));
                  message.append(" doesn't fit in datatype ");
                  message.append("int16_t");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<int16_t>(x);
        });

      size_t size = request->size();
      auto status = library_->WriteArrayI16(session, control, array.data(), size);
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
  ::grpc::Status NiFpgaService::WriteArrayU16(::grpc::ServerContext* context, const WriteArrayU16Request* request, WriteArrayU16Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      auto array_raw = request->array();
      auto array = std::vector<uint16_t>();
      array.reserve(array_raw.size());
      std::transform(
        array_raw.begin(),
        array_raw.end(),
        std::back_inserter(array),
        [](auto x) {
              if (x < std::numeric_limits<uint16_t>::min() || x > std::numeric_limits<uint16_t>::max()) {
                  std::string message("value ");
                  message.append(std::to_string(x));
                  message.append(" doesn't fit in datatype ");
                  message.append("uint16_t");
                  throw nidevice_grpc::ValueOutOfRangeException(message);
              }
              return static_cast<uint16_t>(x);
        });

      size_t size = request->size();
      auto status = library_->WriteArrayU16(session, control, array.data(), size);
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
  ::grpc::Status NiFpgaService::WriteArrayI64(::grpc::ServerContext* context, const WriteArrayI64Request* request, WriteArrayI64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      auto array = const_cast<const int64_t*>(request->array().data());
      size_t size = request->size();
      auto status = library_->WriteArrayI64(session, control, array, size);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiFpgaService::WriteArrayU64(::grpc::ServerContext* context, const WriteArrayU64Request* request, WriteArrayU64Response* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto session_grpc_session = request->session();
      NiFpga_Session session = session_repository_->access_session(session_grpc_session.id(), session_grpc_session.name());
      uint32_t control = request->control();
      auto array = const_cast<const uint64_t*>(request->array().data());
      size_t size = request->size();
      auto status = library_->WriteArrayU64(session, control, array, size);
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::LibraryLoadException& ex) {
      return ::grpc::Status(::grpc::NOT_FOUND, ex.what());
    }
  }


  NiFpgaFeatureToggles::NiFpgaFeatureToggles(
    const nidevice_grpc::FeatureToggles& feature_toggles)
    : is_enabled(
        feature_toggles.is_feature_enabled("nifpga", CodeReadiness::kRelease))
  {
  }
} // namespace nifpga_grpc

