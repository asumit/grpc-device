//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Mock of LibraryInterface for NI-RFMXINSTR
//---------------------------------------------------------------------
#ifndef NIRFMXINSTR_GRPC_MOCK_LIBRARY_H
#define NIRFMXINSTR_GRPC_MOCK_LIBRARY_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "nirfmxinstr_library_interface.h"

namespace ni {
namespace tests {
namespace unit {

class NiRFmxInstrMockLibrary : public nirfmxinstr_grpc::NiRFmxInstrLibraryInterface {
 public:
  MOCK_METHOD(int32, BuildCalibrationPlaneString, (char calibrationPlaneName[], int32 selectorStringLength, char selectorString[]), (override));
  MOCK_METHOD(int32, BuildInstrumentString, (char selectorString[], int32 instrumentNumber, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildLOString, (char selectorString[], int32 loIndex, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildModuleString, (char selectorString[], char moduleName[], int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, BuildPortString, (char selectorString[], char portName[], char deviceName[], int32 channelNumber, int32 selectorStringOutLength, char selectorStringOut[]), (override));
  MOCK_METHOD(int32, CfgExternalAttenuationInterpolationLinear, (niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], int32 format), (override));
  MOCK_METHOD(int32, CfgExternalAttenuationInterpolationNearest, (niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[]), (override));
  MOCK_METHOD(int32, CfgExternalAttenuationInterpolationSpline, (niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[]), (override));
  MOCK_METHOD(int32, CfgExternalAttenuationTable, (niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], float64 frequency[], float64 externalAttenuation[], int32 arraySize), (override));
  MOCK_METHOD(int32, CfgFrequencyReference, (niRFmxInstrHandle instrumentHandle, char channelName[], char frequencyReferenceSource[], float64 frequencyReferenceFrequency), (override));
  MOCK_METHOD(int32, CfgMechanicalAttenuation, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 mechanicalAttenuationAuto, float64 mechanicalAttenuationValue), (override));
  MOCK_METHOD(int32, CfgRFAttenuation, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 rfAttenuationAuto, float64 rfAttenuationValue), (override));
  MOCK_METHOD(int32, CfgSParameterExternalAttenuationTable, (niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], float64 frequency[], int32 frequencyArraySize, NIComplexDouble sParameters[], int32 sParameterTableSize, int32 numberOfPorts, int32 sParameterOrientation), (override));
  MOCK_METHOD(int32, CfgSParameterExternalAttenuationType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 sParameterType), (override));
  MOCK_METHOD(int32, CheckAcquisitionStatus, (niRFmxInstrHandle instrumentHandle, int32* acquisitionDone), (override));
  MOCK_METHOD(int32, CheckIfListExists, (niRFmxInstrHandle instrumentHandle, char listName[], int32* listExists, int32* personality), (override));
  MOCK_METHOD(int32, CheckIfSignalConfigurationExists, (niRFmxInstrHandle instrumentHandle, char signalName[], int32* signalConfigurationExists, int32* personality), (override));
  MOCK_METHOD(int32, Close, (niRFmxInstrHandle instrumentHandle, int32 forceDestroy), (override));
  MOCK_METHOD(int32, DeleteAllExternalAttenuationTables, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, DeleteExternalAttenuationTable, (niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[]), (override));
  MOCK_METHOD(int32, DisableCalibrationPlane, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, EnableCalibrationPlane, (niRFmxInstrHandle instrumentHandle, char selectorString[]), (override));
  MOCK_METHOD(int32, ExportSignal, (niRFmxInstrHandle instrumentHandle, int32 exportSignalSource, char exportSignalOutputTerminal[]), (override));
  MOCK_METHOD(int32, FetchRawIQData, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64 timeout, int32 recordsToFetch, int64 samplesToRead, float64* x0, float64* dx, NIComplexSingle data[], int32 arraySize, int32* actualArraySize, void* reserved), (override));
  MOCK_METHOD(int32, GetAttributeF32, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeF32Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeF64, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeF64Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeI16, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int16* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI32, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI32Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeI64, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int64* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI64Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int64 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeI8, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int8* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeI8Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int8 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeNIComplexDoubleArray, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeNIComplexSingleArray, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeString, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32 arraySize, char attrVal[]), (override));
  MOCK_METHOD(int32, GetAttributeU16, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt16* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeU32, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt32* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeU32Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt32 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeU64Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt64 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAttributeU8, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt8* attrVal), (override));
  MOCK_METHOD(int32, GetAttributeU8Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt8 attrVal[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetAvailablePaths, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char availablePaths[]), (override));
  MOCK_METHOD(int32, GetAvailablePorts, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 arraySize, char availablePorts[]), (override));
  MOCK_METHOD(int32, GetError, (niRFmxInstrHandle instrumentHandle, int32* errorCode, int32 errorDescriptionBufferSize, char errorDescription[]), (override));
  MOCK_METHOD(int32, GetErrorString, (niRFmxInstrHandle instrumentHandle, int32 errorCode, int32 errorDescriptionBufferSize, char errorDescription[]), (override));
  MOCK_METHOD(int32, GetExternalAttenuationTableActualValue, (niRFmxInstrHandle instrumentHandle, char selectorString[], float64* externalAttenuation), (override));
  MOCK_METHOD(int32, GetListNames, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 personalityFilter, char listNames[], int32 listNamesSize, int32* actualListNamesSize, int32 personality[], int32 personalityArraySize, int32* actualPersonalityArraySize), (override));
  MOCK_METHOD(int32, GetNIRFSASession, (niRFmxInstrHandle instrumentHandle, uInt32* niRfsaSession), (override));
  MOCK_METHOD(int32, GetNIRFSASessionArray, (niRFmxInstrHandle instrumentHandle, uInt32 nirfsaSessions[], int32 arraySize, int32* actualArraySize), (override));
  MOCK_METHOD(int32, GetSParameterExternalAttenuationType, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32* sParameterType), (override));
  MOCK_METHOD(int32, GetSelfCalibrateLastDateAndTime, (niRFmxInstrHandle instrumentHandle, char selectorString[], int64 selfCalibrateStep, CVIAbsoluteTime* timestamp), (override));
  MOCK_METHOD(int32, GetSelfCalibrateLastTemperature, (niRFmxInstrHandle instrumentHandle, char selectorString[], int64 selfCalibrateStep, float64* temperature), (override));
  MOCK_METHOD(int32, GetSignalConfigurationNames, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 personalityFilter, char signalNames[], int32 signalNamesSize, int32* actualSignalNamesSize, int32 personality[], int32 personalityArraySize, int32* actualPersonalityArraySize), (override));
  MOCK_METHOD(int32, Initialize, (char resourceName[], char optionString[], niRFmxInstrHandle* handleOut, int32* isNewSession), (override));
  MOCK_METHOD(int32, InitializeFromNIRFSASession, (uInt32 nirfsaSession, niRFmxInstrHandle* handleOut), (override));
  MOCK_METHOD(int32, InitializeFromNIRFSASessionArray, (uInt32 nirfsaSessions[], int32 numberOfNIRFSASessions, niRFmxInstrHandle* handleOut), (override));
  MOCK_METHOD(int32, IsSelfCalibrateValid, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32* selfCalibrateValid, int32* validSteps), (override));
  MOCK_METHOD(int32, LoadAllConfigurations, (niRFmxInstrHandle instrumentHandle, char filePath[], int32 loadRFInstrConfiguration), (override));
  MOCK_METHOD(int32, LoadConfigurations, (niRFmxInstrHandle instrumentHandle, char filePath[]), (override));
  MOCK_METHOD(int32, LoadSParameterExternalAttenuationTableFromS2PFile, (niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[], char s2PFilePath[], int32 sParameterOrientation), (override));
  MOCK_METHOD(int32, ResetAttribute, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID), (override));
  MOCK_METHOD(int32, ResetDriver, (niRFmxInstrHandle instrumentHandle), (override));
  MOCK_METHOD(int32, ResetEntireSession, (niRFmxInstrHandle instrumentHandle), (override));
  MOCK_METHOD(int32, ResetToDefault, (niRFmxInstrHandle instrumentHandle), (override));
  MOCK_METHOD(int32, SaveAllConfigurations, (niRFmxInstrHandle instrumentHandle, char filePath[]), (override));
  MOCK_METHOD(int32, SelectActiveExternalAttenuationTable, (niRFmxInstrHandle instrumentHandle, char selectorString[], char tableName[]), (override));
  MOCK_METHOD(int32, SelfCalibrate, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 stepsToOmit), (override));
  MOCK_METHOD(int32, SelfCalibrateRange, (niRFmxInstrHandle instrumentHandle, char selectorString[], int32 stepsToOmit, float64 minimumFrequency, float64 maximumFrequency, float64 minimumReferenceLevel, float64 maximumReferenceLevel), (override));
  MOCK_METHOD(int32, SendSoftwareEdgeAdvanceTrigger, (niRFmxInstrHandle instrumentHandle), (override));
  MOCK_METHOD(int32, SendSoftwareEdgeStartTrigger, (niRFmxInstrHandle instrumentHandle), (override));
  MOCK_METHOD(int32, SetAttributeF32, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeF32Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float32 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeF64, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeF64Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, float64 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeI16, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int16 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI32, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI32Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int32 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeI64, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int64 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI64Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int64 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeI8, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int8 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeI8Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, int8 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeNIComplexDoubleArray, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, NIComplexDouble attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeNIComplexSingleArray, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, NIComplexSingle attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeString, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, char attrVal[]), (override));
  MOCK_METHOD(int32, SetAttributeU16, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt16 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeU32, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt32 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeU32Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt32 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeU64Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt64 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, SetAttributeU8, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt8 attrVal), (override));
  MOCK_METHOD(int32, SetAttributeU8Array, (niRFmxInstrHandle instrumentHandle, char channelName[], int32 attributeID, uInt8 attrVal[], int32 arraySize), (override));
  MOCK_METHOD(int32, TimestampFromValues, (int64 secondsSince1970, float64 fractionalSeconds, CVIAbsoluteTime* timestamp), (override));
  MOCK_METHOD(int32, ValuesFromTimestamp, (CVIAbsoluteTime timestamp, int64* secondsSince1970, float64* fractionalSeconds), (override));
  MOCK_METHOD(int32, WaitForAcquisitionComplete, (niRFmxInstrHandle instrumentHandle, float64 timeout), (override));
};

}  // namespace unit
}  // namespace tests
}  // namespace ni
#endif  // NIRFMXINSTR_GRPC_MOCK_LIBRARY_H
