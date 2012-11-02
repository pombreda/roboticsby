#include <stdio.h>
#include <windows.h>
#include <locale.h>

HANDLE g_FileHandle;

void enumeratingJoysticks()
{
	JOYCAPS joycaps;
	wprintf(TEXT("\nEnumerating joysticks:\n"));
	for(UINT i=0; i<=joyGetNumDevs(); i++) {
		if(joyGetDevCaps(i, &joycaps, sizeof(JOYCAPS))==JOYERR_NOERROR) {
			wprintf(TEXT("%d: %s with %d axes: ["),i,joycaps.szPname,joycaps.wNumAxes);
			if(joycaps.wNumAxes>=2) {
				wprintf(TEXT("x,y"));
				if(joycaps.wCaps & JOYCAPS_HASV)
					wprintf(TEXT(",v"));
				if(joycaps.wCaps & JOYCAPS_HASR)
					wprintf(TEXT(",r"));
				if(joycaps.wCaps & JOYCAPS_HASZ)
					wprintf(TEXT(",z"));
				if(joycaps.wCaps & JOYCAPS_HASU)
					wprintf(TEXT(",u"));
			}
			wprintf(TEXT("] and %d buttons\n"), joycaps.wNumButtons);
		}
	}
}

void enumeratingCOMPorts()
{
	wprintf(TEXT("\nEnumerating COM ports:\n"));
	for (UINT i=1; i<256; i++)
	{
		wchar_t buffer[32];
		wsprintf(buffer,TEXT("COM%u"), i);

		BOOL bSuccess = FALSE;
		g_FileHandle = CreateFile(buffer, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
		if (g_FileHandle == INVALID_HANDLE_VALUE)
		{
			DWORD dwError = GetLastError();
			if (dwError == ERROR_ACCESS_DENIED || dwError == ERROR_GEN_FAILURE || dwError == ERROR_SHARING_VIOLATION || dwError == ERROR_SEM_TIMEOUT)
				bSuccess = TRUE;
		}
		else
		{
			bSuccess = TRUE;
		}

		CloseHandle(g_FileHandle);
		if (bSuccess)
		{
			wprintf(TEXT("%d: %s\n"), i, buffer);
		}
	}
}

void errorDetailedInformation(LPTSTR lpszFunction) 
{ 
	LPVOID lpMsgBuf;
	DWORD dw = GetLastError(); 

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMsgBuf,
		0, NULL );

	wprintf(TEXT("[%s] failed with error %d: %s"), lpszFunction, dw, (LPTSTR)lpMsgBuf);
}

LPCWSTR multiCharToUniChar(char* charBuffer, wchar_t * wCharBuffer){ 
	size_t len = strlen(charBuffer) + 1; 
	size_t reqsize = 0;
	mbstowcs_s(&reqsize, NULL, 0, charBuffer, len);
	if(!reqsize) return NULL;
	mbstowcs_s(NULL, &wCharBuffer[0], len, charBuffer, len);
	return (LPCWSTR)wCharBuffer; 
}

void usageInformation()
{
	wprintf(TEXT("*********************************\n"));
	wprintf(TEXT("* Roboticsby Tigra test utility *\n"));
	wprintf(TEXT("*********************************\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("Usage options:\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("tigra_joystick_module_test.exe [Joystick Number] [COM Port Name] [Baud Rate]\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("Joystick Number - system number of joystick, usually from 0 to 15\n"));
	wprintf(TEXT("COM Port Name \t- COM Port Name like \"COM1\"\n"));
	wprintf(TEXT("Baud Rate \t- COM Port baud rate like 9600\n"));
	enumeratingCOMPorts();
	enumeratingJoysticks();
}

void exitInformation()
{
	wprintf(TEXT("\nApplication will closed.\n"));
	wprintf(TEXT("\nPress 'Enter' key...\n"));
	int i = getchar();
}

int main(int argc, char** argv)
{
	setlocale(LC_CTYPE,"Russian");

	if (argc<3)
	{
		usageInformation();
		exitInformation();
		return -1;
	}

	UINT jnum = atoi(argv[1]);
	UINT br = atoi(argv[3]);
	wchar_t wBuffer[512];

	wprintf(TEXT("Opening port [%s]\n"),multiCharToUniChar(argv[2], wBuffer));
	g_FileHandle = CreateFile(multiCharToUniChar(argv[2],wBuffer), GENERIC_WRITE|GENERIC_READ, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
	if (INVALID_HANDLE_VALUE == g_FileHandle)
	{
		CloseHandle(g_FileHandle);
		wprintf(TEXT("\nCOM port opening issue.\n"));
		errorDetailedInformation(TEXT("CreateFile"));
		exitInformation();
		return -1;
	}

	wprintf(TEXT("Setting baud rate [%d]\n"),br);
	DCB dcb;
	if (!GetCommState(g_FileHandle,&dcb))
	{
		CloseHandle(g_FileHandle);
		wprintf(TEXT("\nSetting baud rate issue.\n"));
		errorDetailedInformation(TEXT("GetCommState"));
		exitInformation();
		return -1; 
	}

	dcb.BaudRate = br;
	dcb.ByteSize = 8; 
	dcb.StopBits = ONESTOPBIT; 
	dcb.Parity = NOPARITY; 

	if (!SetCommState(g_FileHandle, &dcb))
	{
		CloseHandle(g_FileHandle);
		wprintf(TEXT("\nSetting baud rate issue.\n"));
		errorDetailedInformation(TEXT("SetCommState"));
		exitInformation();
		return -1;
	}

	wprintf(TEXT("\nStart joystick aquire [%d]\n\n"),jnum);
	JOYINFOEX ji;

	while (1)
	{
		
		ZeroMemory(&ji, sizeof(JOYINFOEX));
		ji.dwSize = sizeof(JOYINFOEX);
		ji.dwFlags = JOY_RETURNALL;
		MMRESULT joystickFeadback = joyGetPosEx(jnum, &ji);  

		if(joystickFeadback!=JOYERR_NOERROR)
		{
			if (joystickFeadback == JOYERR_PARMS)
			{
				wprintf(TEXT("\nJoystick - bad parameters.\n"));
			}
			if (joystickFeadback == JOYERR_NOCANDO)
			{
				wprintf(TEXT("\nJoystick - request not completed.\n"));
			}
			if (joystickFeadback == JOYERR_UNPLUGGED)
			{
				wprintf(TEXT("\nJoystick - joystick is unplugged.\n"));
			}
			CloseHandle(g_FileHandle);
			errorDetailedInformation(TEXT("joyGetPosEx"));
			exitInformation();
			return -1;
		}

		BYTE byteBuffer[10];
		byteBuffer[0] = '$';
		byteBuffer[1] = ji.dwButtons&0xff;
		byteBuffer[2] = (ji.dwButtons>>8)&0xff;
		byteBuffer[3] = (ji.dwXpos>>8)&0xff;
		byteBuffer[4] = (ji.dwYpos>>8)&0xff;
		byteBuffer[5] = (ji.dwZpos>>8)&0xff;
		byteBuffer[6] = (ji.dwUpos>>8)&0xff;
		byteBuffer[7] = (ji.dwRpos>>8)&0xff;
		byteBuffer[8] = (BYTE)ji.dwPOV/4500;
		if (byteBuffer[8]>7)
		{
			byteBuffer[8] = 8;
		}
		byteBuffer[9] = '#';
		DWORD w;
		WriteFile(g_FileHandle, byteBuffer, 10, &w, NULL);
		FlushFileBuffers(g_FileHandle);

		printf("%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\n", 
			byteBuffer[0], 
			byteBuffer[1], 
			byteBuffer[2], 
			byteBuffer[3], 
			byteBuffer[4], 
			byteBuffer[5], 
			byteBuffer[6], 
			byteBuffer[7], 
			byteBuffer[8], 
			byteBuffer[9]);
		Sleep(100);
	}
	return 0;
}