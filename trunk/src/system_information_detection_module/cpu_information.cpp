#include "system_information_detection_module.h"

typedef struct cpuid_args_s {
	DWORD eax;
	DWORD ebx;
	DWORD ecx;
	DWORD edx;
} CPUID_ARGS;

typedef struct CPUCOREINFO_s {
	DWORD	dwCPUType;
	DWORD	dwCPUFamily;
	DWORD	dwCPUModel;
	DWORD	dwCPUExtFamily;
	DWORD	dwCPUExtModel;
	DWORD	dwCPUStepping;
	DWORD	dwCPUFeatures;			// result from edx when cpuid called with eax=1
	DWORD	dwCPUPscNewECX;			// result from ecx when cpuid called with eax=1
	DWORD	dwCPUAMDExtSignature;	// AMD extended features
	DWORD	dwBrandIndex;
	DWORD	dwCLFlushLineSize;
	DWORD	dwCPUExtFeatures;		// result from ebx when cpuid called with eax=1
	DWORD	dwFeatures8_1_edx;		// edx = cpuid(0x80000001), NX / EM64T
	DWORD	dwFeatures8_1_ecx;		// Intel - Reserved.  AMD - "AMD Feature Support", esp. CMP legacy, bit 1
	DWORD	dwFeatures8_8_eax;		// eax = cpuid(0x80000008), Virtual/Physical Address size
	DWORD	dwFeatures8_8_ecx;		// Intel - Reserved.  AMD - [7:0] is "Physical Core Count"
} CPUCOREINFO_T;

VOID cpuid32(CPUID_ARGS* p) {
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

DWORD ProcessorCount() {
	SYSTEM_INFO systemInfo;
	ZeroMemory(&systemInfo, sizeof(SYSTEM_INFO));
	::GetSystemInfo( &systemInfo );
	return systemInfo.dwNumberOfProcessors;
}

VOID GetCoreInfo(CPUCOREINFO_T *pCI) {
	DWORD cpuidext=0x00000000;
	DWORD bri = 0;
	DWORD PSCNewFeatures = 0;
	DWORD cpuff = 0;

	CPUID_ARGS ca;
	ca.eax = 0;
	cpuid32(&ca);

	if (ca.eax >= 1) {
		ca.eax = 1;
		cpuid32(&ca);
		cpuidext = ca.eax;
		bri = ca.ebx;
		PSCNewFeatures = ca.ecx;
		cpuff = ca.edx;

		pCI->dwCPUType			= (cpuidext>>12) & 0x3;
		pCI->dwCPUFamily		= (cpuidext>>8)  & 0xf;	
		pCI->dwCPUModel			= (cpuidext>>4)  & 0xf;
		pCI->dwCPUStepping		=  cpuidext      & 0xf;	
		pCI->dwCPUExtFamily		= (cpuidext>>20)  & 0xff;	
		pCI->dwCPUExtModel		= (cpuidext>>16)  & 0xf;
		pCI->dwBrandIndex		= bri & 0xF; // 7:0
		pCI->dwCLFlushLineSize	= (bri & 0xff00) >> 8;
		pCI->dwCPUExtFeatures   = bri;
		pCI->dwCPUPscNewECX		= PSCNewFeatures;
		pCI->dwCPUFeatures		= cpuff;

		ca.eax = 0x80000000;
		cpuid32(&ca);
		if (ca.eax >= 0x80000001) {
			ca.eax = 0x80000001;
			cpuid32(&ca);
			pCI->dwFeatures8_1_edx = ca.edx;
			pCI->dwCPUAMDExtSignature = ca.edx; // redundant, but keep for compatibility
			pCI->dwFeatures8_1_ecx = ca.ecx;
		}

		ca.eax = 0x80000000;
		cpuid32(&ca);
		if (ca.eax >= 0x80000008) {
			ca.eax = 0x80000008;
			cpuid32(&ca);
			pCI->dwFeatures8_8_eax = ca.eax;
			pCI->dwFeatures8_8_ecx = ca.ecx;
		}
	}
}

BOOL GetSSE() {
	CPUCOREINFO_T p;
	ZeroMemory(&p, sizeof(CPUCOREINFO_T));
	GetCoreInfo(&p);
	return ((p.dwCPUFeatures & 0x02000000) != 0);
}

BOOL GetSSE2() {
	CPUCOREINFO_T p;
	ZeroMemory(&p, sizeof(CPUCOREINFO_T));
	GetCoreInfo(&p);
	return ((p.dwCPUFeatures & 0x04000000) != 0);
}

BOOL GetSSE3() {
	CPUCOREINFO_T p;
	ZeroMemory(&p, sizeof(CPUCOREINFO_T));
	GetCoreInfo(&p);
	return ((p.dwCPUPscNewECX & 0x00000001) != 0);
}

BOOL GetSSSE3() {
	CPUCOREINFO_T p;
	ZeroMemory(&p, sizeof(CPUCOREINFO_T));
	GetCoreInfo(&p);
	return ((p.dwCPUPscNewECX & 0x00000200) != 0);
}

BOOL GetSSE4_1() {
	CPUCOREINFO_T p;
	ZeroMemory(&p, sizeof(CPUCOREINFO_T));
	GetCoreInfo(&p);
	return ((p.dwCPUPscNewECX & (1<<19)) != 0);
}

BOOL GetSSE4_2() {
	CPUCOREINFO_T p;
	ZeroMemory(&p, sizeof(CPUCOREINFO_T));
	GetCoreInfo(&p);
	return ((p.dwCPUPscNewECX & (1<<20)) != 0);
}

	VOID GetProcessorString(WCHAR *processorString) {
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
			strncpy_s(outStr,  ARRAYSIZE(outStr) ,(char *)brString, 12*4);
			size_t convertedChars = 0;
			mbstowcs_s(&convertedChars, processorString,  ARRAYSIZE(outStr), outStr,  ARRAYSIZE(outStr));
		} else {
			wcscpy_s(processorString, 49, L"Processor string not supported.");
		}
	}

	VOID GetCPUVendor(WCHAR *processorVendorString) {
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
		mbstowcs_s(&convertedChars, processorVendorString, ARRAYSIZE(outStr), outStr,  ARRAYSIZE(outStr));
	}