#include <windows.h>

typedef struct SystemInformation {
    OSVERSIONINFO	osVersion;
	MEMORYSTATUS	memoryStatus;
	BOOL isHostRunningOnBatteries;
	DWORD processorCount;
}SystemInformationStruct;

typedef struct ModuleInformation {
    DWORD				moduleVersion;
}ModuleInformationStruct;

typedef enum SystemInformationModuleErrorEnum {
    MODULE_NO_ERRROR,
	MODULE_BAD_INPUT_POINTER
};