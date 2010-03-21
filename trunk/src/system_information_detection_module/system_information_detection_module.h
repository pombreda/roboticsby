#ifndef SYSTEM_INFORMATION_DETECTION_MODULE_H
#define SYSTEM_INFORMATION_DETECTION_MODULE_H

#include <windows.h>

typedef struct SystemInformation {
    OSVERSIONINFO	osVersion;
	MEMORYSTATUS	memoryStatus;
	BOOL isHostRunningOnBatteries;
	DWORD dwDirectXVersion;
    WCHAR strDirectXVersion[10];
	DWORD processorCount;
	WCHAR strProcessorString[49];
	WCHAR strProcessorVendorString[13];
	BOOL  isProcessorIntelSSESupport;
	BOOL  isProcessorIntelSSE2Support;
	BOOL  isProcessorIntelSSE3Support;
	BOOL  isProcessorIntelSSSE3Support;
	BOOL  isProcessorIntelSSE4_1Support;
	BOOL  isProcessorIntelSSE4_2Support;
	DWORD gpuVendorId;
	DWORD gpuDeviceId; 
	DWORD gpuVsVersionMax; 
	DWORD gpuPsVersionMax;  
	WCHAR gpuVendorDescriptionString[512]; 
	WCHAR gpuDeviceDescriptionString[512];
}SystemInformationStruct;

typedef struct ModuleInformation {
    DWORD				moduleVersion;
}ModuleInformationStruct;

typedef enum SystemInformationModuleErrorEnum {
    MODULE_NO_ERRROR,
	MODULE_BAD_INPUT_POINTER
};

#endif // SYSTEM_INFORMATION_DETECTION_MODULE_H