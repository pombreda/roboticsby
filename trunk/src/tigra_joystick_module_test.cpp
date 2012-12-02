#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <wchar.h>

HANDLE globalFileHandle, globalThreadHandle;
DWORD globalThreadParam, globalThreadId;
OVERLAPPED globalOverlapWrite, globalOverlapRead;

VOID WINAPI ThreadProcedureCOMPortRead(PVOID*)
{
	
	DWORD bytesRead;
	BYTE readBuffer[128];
	WCHAR finalDataBuffer[128];
	ZeroMemory(&readBuffer, ARRAYSIZE(readBuffer));
	ZeroMemory(&finalDataBuffer, ARRAYSIZE(finalDataBuffer));

	COMSTAT comstat;		
	DWORD btr, temp, mask, signal;	

	ZeroMemory(&globalOverlapRead, sizeof(OVERLAPPED));
	globalOverlapRead.hEvent = CreateEvent(NULL, true, true, NULL);	
	SetCommMask(globalFileHandle, EV_RXCHAR);

	while(TRUE)						
	{
		WaitCommEvent(globalFileHandle, &mask, &globalOverlapRead);              
		if (globalOverlapRead.hEvent != INVALID_HANDLE_VALUE)
		{
			signal = WaitForSingleObject(globalOverlapRead.hEvent, INFINITE);	
			if(signal == WAIT_OBJECT_0)				        
			{
				if(GetOverlappedResult(globalFileHandle, &globalOverlapRead, &temp, true)) 
					if((mask & EV_RXCHAR)!=0)					
					{
						ClearCommError(globalFileHandle, &temp, &comstat);		
						btr = comstat.cbInQue;                          	
						if(btr)                         			
						{
							BOOL readFileResult = ReadFile(globalFileHandle, readBuffer, 127, &bytesRead, &globalOverlapRead);
							if (readFileResult && bytesRead > 0)
							{
								int counter = 0;
								for (UINT i=0; i<128; i++)
								{
									USHORT characterInteger = btowc(readBuffer[i]);
									if (characterInteger>31)
									{
										finalDataBuffer[counter] = characterInteger;
										counter++;
									}								
								}
								wprintf(TEXT("Recieving from robot's: [%s]\n"),finalDataBuffer);
								ZeroMemory(&readBuffer, ARRAYSIZE(readBuffer));
								ZeroMemory(&finalDataBuffer, ARRAYSIZE(finalDataBuffer));
							}                      		
						}
					}
			}
		}
	}
}

void enumeratingJoysticks()
{
	JOYCAPS joycaps;
	wprintf(TEXT("\nEnumerating joysticks:\n"));
	UINT joystick_counter=0;
	for(UINT i=0; i<=joyGetNumDevs(); i++) {
		if(joyGetDevCaps(i, &joycaps, sizeof(JOYCAPS))==JOYERR_NOERROR) {
			joystick_counter++;
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
	if (joystick_counter == 0)
	{
		wprintf(TEXT("We could not find any joystick devices.\n"));
	}
}

void enumeratingCOMPorts()
{
	wprintf(TEXT("\nEnumerating COM ports:\n"));
	for (UINT i=1; i<256; i++)
	{
		WCHAR buffer[32];
		wsprintf(buffer,TEXT("\\\\.\\COM%u"), i);

		BOOL bSuccess = FALSE;
		globalFileHandle = CreateFile(buffer, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
		if (globalFileHandle == INVALID_HANDLE_VALUE)
		{
			DWORD dwError = GetLastError();
			if (dwError == ERROR_ACCESS_DENIED || dwError == ERROR_GEN_FAILURE || dwError == ERROR_SHARING_VIOLATION || dwError == ERROR_SEM_TIMEOUT)
				bSuccess = TRUE;
		}
		else
		{
			bSuccess = TRUE;
		}

		CloseHandle(globalFileHandle);
		if (bSuccess)
		{
			wprintf(TEXT("%u: COM%u\n"), i, i);
		}
	}
}

void errorDetailedInformation(LPTSTR lpszFunctionName) 
{ 
	LPVOID lpMessageBuffer;
	DWORD dwLastError = GetLastError(); 

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dwLastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &lpMessageBuffer,
		0, NULL );

	wprintf(TEXT("[%s] failed with error %d: %s"), lpszFunctionName, dwLastError, (LPTSTR)lpMessageBuffer);
}

LPCWSTR multiCharToUniChar(char* charBuffer, WCHAR* wCharBuffer){ 
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
	WCHAR wBuffer[512];

	wprintf(TEXT("Opening port [%s]\n"),multiCharToUniChar(argv[2], wBuffer));
	globalFileHandle = CreateFile(multiCharToUniChar(argv[2],wBuffer), GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
	if (INVALID_HANDLE_VALUE == globalFileHandle)
	{
		CloseHandle(globalFileHandle);
		wprintf(TEXT("\nCOM port opening issue.\n"));
		errorDetailedInformation(TEXT("CreateFile"));
		exitInformation();
		return -1;
	}

	wprintf(TEXT("Setting baud rate [%d]\n"),br);

	DCB dcb;
	ZeroMemory(&dcb, sizeof(DCB));

	if (!GetCommState(globalFileHandle,&dcb))
	{
		CloseHandle(globalFileHandle);
		wprintf(TEXT("\nSetting baud rate issue.\n"));
		errorDetailedInformation(TEXT("GetCommState"));
		exitInformation();
		return -1; 
	}

	dcb.BaudRate = br;
	dcb.ByteSize = 8; 
	dcb.StopBits = ONESTOPBIT; 
	dcb.Parity = NOPARITY; 

	if (!SetCommState(globalFileHandle, &dcb))
	{
		CloseHandle(globalFileHandle);
		wprintf(TEXT("\nSetting baud rate issue.\n"));
		errorDetailedInformation(TEXT("SetCommState"));
		exitInformation();
		return -1;
	}

	COMMTIMEOUTS ComTimeouts;
	ZeroMemory(&ComTimeouts, sizeof(COMMTIMEOUTS));
	ComTimeouts.ReadIntervalTimeout = MAXDWORD;
	ComTimeouts.ReadTotalTimeoutConstant = 0;
	ComTimeouts.ReadTotalTimeoutMultiplier = 100;
	ComTimeouts.WriteTotalTimeoutConstant = 1;
	ComTimeouts.WriteTotalTimeoutMultiplier = 100;

	if(!SetCommTimeouts(globalFileHandle, &ComTimeouts))
	{
		CloseHandle(globalFileHandle);
		wprintf(TEXT("\nSetting COM Port Timeouts issue.\n"));
		errorDetailedInformation(TEXT("SetCommTimeouts"));
		exitInformation();
		return -1;
	}

	if(!PurgeComm(globalFileHandle, PURGE_RXCLEAR))
	{
		CloseHandle(globalFileHandle);
		wprintf(TEXT("\nPurge COMM for RX issue.\n"));
		errorDetailedInformation(TEXT("PurgeComm"));
		exitInformation();
		return -1;
	}

	if(!PurgeComm(globalFileHandle, PURGE_TXCLEAR))
	{
		CloseHandle(globalFileHandle);
		wprintf(TEXT("\nPurge COMM for TX issue.\n"));
		errorDetailedInformation(TEXT("PurgeComm"));
		exitInformation();
		return -1;
	} 	

	globalThreadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcedureCOMPortRead, &globalThreadParam, 0, &globalThreadId);
	if (INVALID_HANDLE_VALUE == globalThreadHandle)
	{
		CloseHandle(globalThreadHandle);
		wprintf(TEXT("\nCreate Thread for COM Port Read issue.\n"));
		errorDetailedInformation(TEXT("CreateThread"));
		exitInformation();
		return -1;
	}

	wprintf(TEXT("\nStart joystick aquire [%d]\n\n"),jnum);
	JOYINFOEX ji;

	ZeroMemory(&globalOverlapWrite, sizeof(OVERLAPPED));

	while (TRUE)
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
			CloseHandle(globalFileHandle);
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

		DWORD bytesWrite;

		WriteFile(globalFileHandle, byteBuffer, 10, &bytesWrite, &globalOverlapWrite);
		FlushFileBuffers(globalFileHandle);

		wprintf(TEXT("Sending to robot's: [%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X]\n"), 
			byteBuffer[0], byteBuffer[1], byteBuffer[2], 
			byteBuffer[3], byteBuffer[4], byteBuffer[5], 
			byteBuffer[6], byteBuffer[7], byteBuffer[8], byteBuffer[9]);
		Sleep(100);
	}
}