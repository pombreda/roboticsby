#include <iostream>
#include "system_information_detection_module\system_information_detection_module.h"

VOID showModuleInformation()
{
	HINSTANCE hModule=NULL;
	typedef  SystemInformationModuleErrorEnum (__cdecl MESS)(ModuleInformationStruct *p);
	MESS* me=NULL;
	hModule=::LoadLibrary(L"system_information_detection_module.dll");
	if (hModule!=NULL)
	{
		me=(MESS*)::GetProcAddress((HMODULE)hModule,"ModuleInformation");
		if (me!=NULL)
		{
			ModuleInformationStruct s;
			ZeroMemory(&s, sizeof(ModuleInformation));
			DWORD result;
			result=(*me)(&s);
			if (result == MODULE_NO_ERRROR)
			{
				wprintf(L"ModuleInformation\n");
				wprintf(L"Module Version: %u\n\n",s.moduleVersion); 
			}
		}
		else wprintf(L"Error Load function\n");
		::FreeLibrary(hModule); 
	}
	else wprintf(L"Error load dll\n");
}

VOID showSystemInformation()
{
	HINSTANCE hModule=NULL;
	typedef  SystemInformationModuleErrorEnum (__cdecl MESS)(SystemInformationStruct *p);
	MESS* me=NULL;
	hModule=::LoadLibrary(L"system_information_detection_module.dll");
	if (hModule!=NULL)
	{
		me=(MESS*)::GetProcAddress((HMODULE)hModule,"SystemInformation");
		if (me!=NULL)
		{
			SystemInformation s;
			ZeroMemory(&s, sizeof(SystemInformation));
			DWORD result;
			result=(*me)(&s);
			if (result == MODULE_NO_ERRROR)
			{
				wprintf(L"SystemInformation\n");
				wprintf(L"OS: Windows %lu.%lu.%lu\n",s.osVersion.dwMajorVersion,s.osVersion.dwMinorVersion,s.osVersion.dwBuildNumber);
				wprintf(L"Memory: %I64uK total, %I64uK free\n",s.memoryStatus.ullTotalPhys/1024,s.memoryStatus.ullAvailPhys/1024);
				if (s.isHostRunningOnBatteries) wprintf(L"Power status: %s\n",L"Battery");
				else wprintf(L"Power status: %s\n",L"AC");
				wprintf(L"DirectX version string: %s\n",s.strDirectXVersion);
				wprintf(L"DirectX version hex number: %x\n",s.dwDirectXVersion);
				wprintf(L"Processor String: %s\n",s.strProcessorString);
				wprintf(L"Processor Vendor String: %s\n",s.strProcessorVendorString);
				wprintf(L"Processor Support Intel SSE: %s\n",s.isProcessorIntelSSESupport ? L"Yes" : L"No" );
				wprintf(L"Processor Support Intel SSE2: %s\n",s.isProcessorIntelSSE2Support ? L"Yes" : L"No" );
				wprintf(L"Processor Support Intel SSE3: %s\n",s.isProcessorIntelSSE3Support ? L"Yes" : L"No" );
				wprintf(L"Processor Support Intel SSSE3: %s\n",s.isProcessorIntelSSSE3Support ? L"Yes" : L"No" );
				wprintf(L"Processor Support Intel SSE4_1: %s\n",s.isProcessorIntelSSE4_1Support ? L"Yes" : L"No" );
				wprintf(L"Processor Support Intel SSE4_2: %s\n",s.isProcessorIntelSSE4_2Support ? L"Yes" : L"No" );
				wprintf(L"Number of available processors: %u\n",s.processorCount);
				wprintf(L"GPU vendor string: %s\n",s.gpuVendorDescriptionString);
				wprintf(L"GPU vendor hex number: %x\n",s.gpuVendorId);
				wprintf(L"GPU device string: %s\n",s.gpuDeviceDescriptionString);
				wprintf(L"GPU device hex number: %x\n",s.gpuDeviceId);
				wprintf(L"GPU max vertex shader hardware support: %u\n",s.gpuVsVersionMax);
				wprintf(L"GPU max pixel shader hardware support: %u\n",s.gpuPsVersionMax);
			}
		}
		else wprintf(L"Error Load function\n");
		::FreeLibrary(hModule); 
	}
	else wprintf(L"Error load dll\n");
}

INT main()
{
	showModuleInformation();
	showSystemInformation();
	char c = getchar();
	return 0;
}