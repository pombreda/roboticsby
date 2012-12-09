#include "system_information_detection_module.h"

extern VOID GetProcessorString(WCHAR *processorString);

extern HRESULT GetDXVersion( DWORD* pdwDirectXVersion, WCHAR* strDirectXVersion, SIZE_T cchDirectXVersion = 10 );

extern DWORD ProcessorCount();

extern VOID GetCPUVendor(WCHAR *processorVendorString);

extern VOID GetGPUInformation(DWORD* vendorId, DWORD* deviceId, DWORD* vsVersionMax, DWORD* psVersionMax,  WCHAR* vendorDescriptionString, WCHAR* deviceDescriptionString);

extern BOOL GetSSE();
extern BOOL GetSSE2();
extern BOOL GetSSE3();
extern BOOL GetSSSE3();
extern BOOL GetSSE4_1();
extern BOOL GetSSE4_2();

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
		p->memoryStatus.dwLength = sizeof(p->memoryStatus);
		GlobalMemoryStatusEx(&p->memoryStatus);
		p->isHostRunningOnBatteries = IsRunningOnBatteries();
		p->processorCount = ProcessorCount();
		GetProcessorString(p->strProcessorString);
		GetCPUVendor(p->strProcessorVendorString);
		p->isProcessorIntelSSESupport = GetSSE();
		p->isProcessorIntelSSE2Support = GetSSE2();
		p->isProcessorIntelSSE3Support = GetSSE3();
		p->isProcessorIntelSSSE3Support = GetSSSE3();
		p->isProcessorIntelSSE4_1Support = GetSSE4_1();
		p->isProcessorIntelSSE4_2Support = GetSSE4_2();
		GetDXVersion(&p->dwDirectXVersion, p->strDirectXVersion, ARRAYSIZE(p->strDirectXVersion));
		GetGPUInformation(&p->gpuVendorId, &p->gpuDeviceId, &p->gpuVsVersionMax, &p->gpuPsVersionMax,  p->gpuVendorDescriptionString, p->gpuDeviceDescriptionString);
		return MODULE_NO_ERRROR;
	}
	return MODULE_BAD_INPUT_POINTER;
}