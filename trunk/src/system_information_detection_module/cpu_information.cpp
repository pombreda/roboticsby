#include "system_information_detection_module.h"

typedef struct cpuid_args_s {
	DWORD eax;
	DWORD ebx;
	DWORD ecx;
	DWORD edx;
} CPUID_ARGS;

void cpuid32(CPUID_ARGS* p) {
	__asm {
		mov	edi, p
		mov eax, [edi]
		mov ecx, [edi+8] // for functions such as eax=4
		cpuid
		mov [edi], eax
		mov [edi+4], ebx
		mov [edi+8], ecx
		mov [edi+12], edx
	}
}

DWORD processorCount() 
{
    SYSTEM_INFO systemInfo;
	ZeroMemory(&systemInfo, sizeof(SYSTEM_INFO));
    ::GetSystemInfo( &systemInfo );
	return systemInfo.dwNumberOfProcessors;
}

void GetProcessorString(WCHAR *processorString) {
	char outStr[49];
	DWORD maxb = 0;
	DWORD cpuid_arg = 0x80000000;
	DWORD brString[12];
	CPUID_ARGS ca;

	outStr[49-1] = '\0';
	
	ca.eax = cpuid_arg;
	cpuid32(&ca);
	maxb = ca.eax;
	if (maxb >= 0x80000004) {
		ca.eax = 0x80000002;
		cpuid32(&ca);
		brString[0] = ca.eax;
		brString[1] = ca.ebx;
		brString[2] = ca.ecx;
		brString[3] = ca.edx;

		ca.eax = 0x80000003;
		cpuid32(&ca);
		brString[4] = ca.eax;
		brString[5] = ca.ebx;
		brString[6] = ca.ecx;
		brString[7] = ca.edx;

		ca.eax = 0x80000004;
		cpuid32(&ca);
		brString[8] = ca.eax;
		brString[9] = ca.ebx;
		brString[10] = ca.ecx;
		brString[11] = ca.edx;
		strncpy_s(outStr, 49 ,(char *)brString, 12*4);
		size_t convertedChars = 0;
		mbstowcs_s(&convertedChars, processorString, 49, outStr, _TRUNCATE);
	} else {
		wcscpy_s(processorString, 49, L"Processor string not supported.");
	}
}

void GetCPUVendor(WCHAR *processorVendorString) {
	char outStr[13];
	BYTE vendor_id[]="------------";
	CPUID_ARGS ca;

	outStr[13-1] = '\0';
	
	ca.eax = 0;
	cpuid32(&ca);
	((DWORD*)vendor_id)[0] = ca.ebx;
	((DWORD*)vendor_id)[1] = ca.edx;
	((DWORD*)vendor_id)[2] = ca.ecx;
	
	strncpy_s(outStr, ARRAYSIZE(outStr),(char *)vendor_id, ARRAYSIZE(vendor_id));
	size_t convertedChars = 0;
	mbstowcs_s(&convertedChars, processorVendorString, ARRAYSIZE(outStr), outStr, _TRUNCATE);
}