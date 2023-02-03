
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service implementation for the NI-RFMXWLAN-RESTRICTED Metadata
//---------------------------------------------------------------------
#include "nirfmxwlan_restricted_service.h"

#include <sstream>
#include <fstream>
#include <iostream>
#include <atomic>
#include <vector>
#include <server/converters.h>

namespace nirfmxwlan_restricted_grpc {

  using nidevice_grpc::converters::allocate_output_storage;
  using nidevice_grpc::converters::calculate_linked_array_size;
  using nidevice_grpc::converters::convert_from_grpc;
  using nidevice_grpc::converters::convert_to_grpc;
  using nidevice_grpc::converters::MatchState;

  const auto kErrorReadBufferTooSmall = -200229;
  const auto kWarningCAPIStringTruncatedToFitBuffer = 200026;

  NiRFmxWLANRestrictedService::NiRFmxWLANRestrictedService(
      NiRFmxWLANRestrictedLibraryInterface* library,
      ResourceRepositorySharedPtr resource_repository,
      const NiRFmxWLANRestrictedFeatureToggles& feature_toggles)
      : library_(library),
      session_repository_(resource_repository),
      feature_toggles_(feature_toggles)
  {
  }

  NiRFmxWLANRestrictedService::~NiRFmxWLANRestrictedService()
  {
  }

  // Returns true if it's safe to use outputs of a method with the given status.
  inline bool status_ok(int32 status)
  {
    return status >= 0;
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiRFmxWLANRestrictedService::GetChannelList(::grpc::ServerContext* context, const GetChannelListRequest* request, GetChannelListResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto instrument_grpc_session = request->instrument();
      niRFmxInstrHandle instrument = session_repository_->access_session(instrument_grpc_session.name());
      auto selector_string_mbcs = convert_from_grpc<std::string>(request->selector_string());
      char* selector_string = (char*)selector_string_mbcs.c_str();
      int32 wlan_band = request->wlan_band();
      int32 actual_array_size {};
      while (true) {
        auto status = library_->GetChannelList(instrument, selector_string, wlan_band, nullptr, nullptr, 0, &actual_array_size);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
        }
        response->mutable_center_frequencies()->Resize(actual_array_size, 0);
        float64* center_frequencies = response->mutable_center_frequencies()->mutable_data();
        response->mutable_channel_bandwidths()->Resize(actual_array_size, 0);
        float64* channel_bandwidths = response->mutable_channel_bandwidths()->mutable_data();
        auto array_size = actual_array_size;
        status = library_->GetChannelList(instrument, selector_string, wlan_band, center_frequencies, channel_bandwidths, array_size, &actual_array_size);
        if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
          // buffer is now too small, try again
          continue;
        }
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
        }
        response->set_status(status);
        response->mutable_center_frequencies()->Resize(actual_array_size, 0);
        response->mutable_channel_bandwidths()->Resize(actual_array_size, 0);
        response->set_actual_array_size(actual_array_size);
        return ::grpc::Status::OK;
      }
    }
    catch (nidevice_grpc::NonDriverException& ex) {
      return ex.GetStatus();
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiRFmxWLANRestrictedService::OFDMModAccFetchCommonPilotErrorTraceIndB(::grpc::ServerContext* context, const OFDMModAccFetchCommonPilotErrorTraceIndBRequest* request, OFDMModAccFetchCommonPilotErrorTraceIndBResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto instrument_grpc_session = request->instrument();
      niRFmxInstrHandle instrument = session_repository_->access_session(instrument_grpc_session.name());
      auto selector_string_mbcs = convert_from_grpc<std::string>(request->selector_string());
      char* selector_string = (char*)selector_string_mbcs.c_str();
      float64 timeout = request->timeout();
      float64 x0 {};
      float64 dx {};
      int32 actual_array_size {};
      while (true) {
        auto status = library_->OFDMModAccFetchCommonPilotErrorTraceIndB(instrument, selector_string, timeout, &x0, &dx, nullptr, nullptr, 0, &actual_array_size);
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
        }
        response->mutable_common_pilot_error_magnitude()->Resize(actual_array_size, 0);
        float32* common_pilot_error_magnitude = response->mutable_common_pilot_error_magnitude()->mutable_data();
        response->mutable_common_pilot_error_phase()->Resize(actual_array_size, 0);
        float32* common_pilot_error_phase = response->mutable_common_pilot_error_phase()->mutable_data();
        auto array_size = actual_array_size;
        status = library_->OFDMModAccFetchCommonPilotErrorTraceIndB(instrument, selector_string, timeout, &x0, &dx, common_pilot_error_magnitude, common_pilot_error_phase, array_size, &actual_array_size);
        if (status == kErrorReadBufferTooSmall || status == kWarningCAPIStringTruncatedToFitBuffer) {
          // buffer is now too small, try again
          continue;
        }
        if (!status_ok(status)) {
          return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
        }
        response->set_status(status);
        response->set_x0(x0);
        response->set_dx(dx);
        response->mutable_common_pilot_error_magnitude()->Resize(actual_array_size, 0);
        response->mutable_common_pilot_error_phase()->Resize(actual_array_size, 0);
        response->set_actual_array_size(actual_array_size);
        return ::grpc::Status::OK;
      }
    }
    catch (nidevice_grpc::NonDriverException& ex) {
      return ex.GetStatus();
    }
  }

  //---------------------------------------------------------------------
  //---------------------------------------------------------------------
  ::grpc::Status NiRFmxWLANRestrictedService::OFDMModAccNoiseCalibrate(::grpc::ServerContext* context, const OFDMModAccNoiseCalibrateRequest* request, OFDMModAccNoiseCalibrateResponse* response)
  {
    if (context->IsCancelled()) {
      return ::grpc::Status::CANCELLED;
    }
    try {
      auto instrument_grpc_session = request->instrument();
      niRFmxInstrHandle instrument = session_repository_->access_session(instrument_grpc_session.name());
      auto selector_string_mbcs = convert_from_grpc<std::string>(request->selector_string());
      char* selector_string = (char*)selector_string_mbcs.c_str();
      int32 shared_lo_connection = request->shared_lo_connection();
      auto status = library_->OFDMModAccNoiseCalibrate(instrument, selector_string, shared_lo_connection);
      if (!status_ok(status)) {
        return ConvertApiErrorStatusForNiRFmxInstrHandle(context, status, instrument);
      }
      response->set_status(status);
      return ::grpc::Status::OK;
    }
    catch (nidevice_grpc::NonDriverException& ex) {
      return ex.GetStatus();
    }
  }


  NiRFmxWLANRestrictedFeatureToggles::NiRFmxWLANRestrictedFeatureToggles(
    const nidevice_grpc::FeatureToggles& feature_toggles)
    : is_enabled(
        feature_toggles.is_feature_enabled("nirfmxwlan_restricted", CodeReadiness::kRelease))
  {
  }
} // namespace nirfmxwlan_restricted_grpc

