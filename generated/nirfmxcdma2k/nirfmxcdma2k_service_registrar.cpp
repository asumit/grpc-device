
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Service registrar implementation for the NI-rfmxcdma2k Metadata
//---------------------------------------------------------------------
#include "nirfmxcdma2k_library.h"

#include <grpcpp/server_builder.h>

#include "nirfmxcdma2k_service.h"
#include "nirfmxcdma2k_service_registrar.h"

namespace nirfmxcdma2k_grpc {

namespace {
struct LibraryAndService {
  LibraryAndService(
    const std::shared_ptr<nidevice_grpc::SessionResourceRepository<niRFmxInstrHandle>>& resource_repository,
    const NiRFmxCDMA2kFeatureToggles& feature_toggles) 
      : library(), 
      service(
        &library, 
        resource_repository,
        feature_toggles) {
  }
  NiRFmxCDMA2kLibrary library;
  NiRFmxCDMA2kService service;
};
}

std::shared_ptr<void> register_service(
  grpc::ServerBuilder& builder, 
  const std::shared_ptr<nidevice_grpc::SessionResourceRepository<niRFmxInstrHandle>>& resource_repository,
  const nidevice_grpc::FeatureToggles& feature_toggles)
{
  auto toggles = NiRFmxCDMA2kFeatureToggles(feature_toggles);

  if (toggles.is_enabled)
  {
    auto library_and_service_ptr = std::make_shared<LibraryAndService>(
      resource_repository,
      toggles);
    auto& service = library_and_service_ptr->service;
    builder.RegisterService(&service);
    return library_and_service_ptr;
  }

  return {};
}

} // nirfmxcdma2k_grpc
