//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryWrapper for NI-FAKE
//---------------------------------------------------------------------
#ifndef NI_FAKE_GRPC_MOCK_LIBRARY_WRAPPER_H
#define NI_FAKE_GRPC_MOCK_LIBRARY_WRAPPER_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "nifake_library_wrapper.h"

namespace ni {
namespace tests {
namespace unit {
namespace fake {
namespace grpc {

namespace driverNamespace = ni::fake::grpc;

class NiFakeMockLibraryWrapper : public driverNamespace::NiFakeLibraryWrapper {
 public:
  MOCK_METHOD(::grpc::Status, check_function_exists, (std::string functionName), (override));
  MOCK_METHOD(ViStatus, Abort, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, EnumInputFunctionWithDefaults, (ViSession vi, ViInt16 aTurtle), (override));
  MOCK_METHOD(ViStatus, GetABoolean, (ViSession vi, ViBoolean* aBoolean), (override));
  MOCK_METHOD(ViStatus, GetANumber, (ViSession vi, ViInt16* aNumber), (override));
  MOCK_METHOD(ViStatus, GetArraySizeForPythonCode, (ViSession vi, ViInt32* sizeOut), (override));
  MOCK_METHOD(ViStatus, GetAttributeViBoolean, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetAttributeViInt32, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetAttributeViInt64, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetAttributeViReal64, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64* attributeValue), (override));
  MOCK_METHOD(ViStatus, GetCalDateAndTime, (ViSession vi, ViInt32 calType, ViInt32* month, ViInt32* day, ViInt32* year, ViInt32* hour, ViInt32* minute), (override));
  MOCK_METHOD(ViStatus, GetCalInterval, (ViSession vi, ViInt32* months), (override));
  MOCK_METHOD(ViStatus, GetEnumValue, (ViSession vi, ViInt32* aQuantity, ViInt16* aTurtle), (override));
  MOCK_METHOD(ViStatus, InitWithOptions, (ViString resourceName, ViBoolean idQuery, ViBoolean resetDevice, ViConstString optionString, ViSession* vi), (override));
  MOCK_METHOD(ViStatus, Initiate, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, OneInputFunction, (ViSession vi, ViInt32 aNumber), (override));
  MOCK_METHOD(ViStatus, ParametersAreMultipleTypes, (ViSession vi, ViBoolean aBoolean, ViInt32 anInt32, ViInt64 anInt64, ViInt16 anIntEnum, ViReal64 aFloat, ViReal64 aFloatEnum, ViInt32 stringSize, ViConstString aString), (override));
  MOCK_METHOD(ViStatus, PoorlyNamedSimpleFunction, (ViSession vi), (override));
  MOCK_METHOD(ViStatus, Read, (ViSession vi, ViReal64 maximumTime, ViReal64* reading), (override));
  MOCK_METHOD(ViStatus, ReadFromChannel, (ViSession vi, ViConstString channelName, ViInt32 maximumTime, ViReal64* reading), (override));
  MOCK_METHOD(ViStatus, ReturnDurationInSeconds, (ViSession vi, ViReal64* timedelta), (override));
  MOCK_METHOD(ViStatus, SetAttributeViBoolean, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViInt32, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViInt64, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64 attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViReal64, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 attributeValue), (override));
  MOCK_METHOD(ViStatus, SetAttributeViString, (ViSession vi, ViConstString channelName, ViAttr attributeId, ViConstString attributeValue), (override));
  MOCK_METHOD(ViStatus, StringValuedEnumInputFunctionWithDefaults, (ViSession vi, ViConstString aMobileOSName), (override));
  MOCK_METHOD(ViStatus, TwoInputFunction, (ViSession vi, ViReal64 aNumber, ViString aString), (override));
  MOCK_METHOD(ViStatus, Use64BitNumber, (ViSession vi, ViInt64 input, ViInt64* output), (override));
  MOCK_METHOD(ViStatus, close, (ViSession vi), (override));
};

}  // namespace grpc
}  // namespace fake
}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NI_FAKE_GRPC_MOCK_LIBRARY_WRAPPER_H
