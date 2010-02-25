#include "system_information_detection_module.h"

extern VOID GetProcessorString(WCHAR *processorString);

extern HRESULT GetDXVersion( DWORD* pdwDirectXVersion, WCHAR* strDirectXVersion, SIZE_T cchDirectXVersion = 10 );

extern DWORD processorCount();

extern VOID GetCPUVendor(WCHAR *processorVendorString);

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)  
{
	switch( fdwReason ){
		case DLL_PROCESS_ATTACH:

			break;
		case DLL_THREAD_ATTACH:         

			break;        
		case DLL_THREAD_DETACH:

			break;
		case DLL_PROCESS_DETACH:

			break;    
	}    
	return TRUE;  
}

BOOL IsRunningOnBatteries() 
{
	SYSTEM_POWER_STATUS pStatus;
	ZeroMemory(&pStatus, sizeof(SYSTEM_POWER_STATUS));
	if (!GetSystemPowerStatus(&pStatus)) {
		return false;
	}
	BOOL bIsOnBatteryPower  = (pStatus.ACLineStatus != 1);
    BOOL bIsBatteryCharging = ((pStatus.BatteryFlag & 8) == 8);
    BOOL bIsBatteryMissing = ((pStatus.BatteryFlag & 128) == 128);
	return (bIsOnBatteryPower && !bIsBatteryCharging && !bIsBatteryMissing);
}

extern "C" __declspec(dllexport) SystemInformationModuleErrorEnum __cdecl ModuleInformation(ModuleInformationStruct *p)
{
	if (p!=NULL)
	{
		p->moduleVersion = 1;
		return MODULE_NO_ERRROR;
	}
	return  MODULE_BAD_INPUT_POINTER;
}

extern "C" __declspec(dllexport)  SystemInformationModuleErrorEnum __cdecl SystemInformation(SystemInformationStruct *p)
{
	if (p!=NULL)
	{
		ZeroMemory(&p->osVersion, sizeof(OSVERSIONINFO));
		p->osVersion.dwOSVersionInfoSize = sizeof(p->osVersion);
		GetVersionEx((OSVERSIONINFO*)&p->osVersion);
		GlobalMemoryStatus(&p->memoryStatus);
		p->isHostRunningOnBatteries = IsRunningOnBatteries();
		p->processorCount = processorCount();
		GetProcessorString(p->strProcessorString);
		GetCPUVendor(p->strProcessorVendorString);
		GetDXVersion(&p->dwDirectXVersion, p->strDirectXVersion, ARRAYSIZE(p->strDirectXVersion));
		return MODULE_NO_ERRROR;
	}
	return MODULE_BAD_INPUT_POINTER;
}