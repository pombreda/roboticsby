#ifndef SYSTEM_INFORMATION_DETECTION_MODULE_H
#define SYSTEM_INFORMATION_DETECTION_MODULE_H

#include <windows.h>

typedef struct SystemInformation {
    OSVERSIONINFO	osVersion;
	MEMORYSTATUS	memoryStatus;
	BOOL isHostRunningOnBatteries;
	DWORD processorCount;
	DWORD dwDirectXVersion;
    WCHAR strDirectXVersion[10];
}SystemInformationStruct;

typedef struct ModuleInformation {
    DWORD				moduleVersion;
}ModuleInformationStruct;

typedef enum SystemInformationModuleErrorEnum {
    MODULE_NO_ERRROR,
	MODULE_BAD_INPUT_POINTER
};

#endif // SYSTEM_INFORMATION_DETECTION_MODULE_H