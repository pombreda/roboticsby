#include <iostream>
#include "system_information_detection_module\system_information_detection_module.h"

void showModuleInformation()
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
				wprintf(L"Module Version: %d\n\n",s.moduleVersion); 
			}
		}
		else wprintf(L"Error Load function\n");
		::FreeLibrary(hModule); 
	}
	else wprintf(L"Error load dll\n");
}

void showSystemInformation()
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
				wprintf(L"OS: Windows %ld.%ld.%ld\n",s.osVersion.dwMajorVersion,s.osVersion.dwMinorVersion,s.osVersion.dwBuildNumber);
				wprintf(L"Memory: %ldK total, %ldK free\n",s.memoryStatus.dwTotalPhys/1024L,s.memoryStatus.dwAvailPhys/1024L);
				if (s.isHostRunningOnBatteries) wprintf(L"Power status: %s\n",L"Battery");
				else wprintf(L"Power status: %s\n",L"AC");
				wprintf(L"DirectX version string: %s\n",s.strDirectXVersion);
				wprintf(L"DirectX version hex number: %x\n",s.dwDirectXVersion);
				wprintf(L"Processor String: %s\n",s.strProcessorString);
				wprintf(L"Number of available processors: %d\n",s.processorCount);
			}
		}
		else wprintf(L"Error Load function\n");
		::FreeLibrary(hModule); 
	}
	else wprintf(L"Error load dll\n");
}

int main()
{
	showModuleInformation();
	showSystemInformation();
	char c = getchar();
	return 0;
}