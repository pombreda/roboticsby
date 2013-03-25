#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <wchar.h>

HANDLE globalFileHandle;
HANDLE globalThreadCOMPortReadHandle;
DWORD globalThreadCOMPortReadParam, globalThreadCOMPortReadId;
HANDLE globalThreadConsoleReadHandle;
DWORD globalThreadConsoleReadParam, globalThreadConsoleReadId;
OVERLAPPED globalOverlapWrite, globalOverlapRead;
BOOL globalIsJoystickUsed = TRUE;
BOOL globalQAEDPressed[4] = {FALSE,FALSE,FALSE,FALSE};
BOOL globalCursorPressed[4] = {FALSE,FALSE,FALSE,FALSE};
USHORT globalRobotDrivePowerLevel = 0;

VOID errorDetailedInformation(LPTSTR functionName) 
{ 
	LPVOID messageBuffer;
	DWORD lastError = GetLastError(); 

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		lastError,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR) &messageBuffer,
		0, NULL );

	wprintf(TEXT("[%s] failed with error %u: %s"), functionName, lastError, (LPTSTR)messageBuffer);
}

VOID WINAPI ThreadProcedureConsoleRead(PVOID*)
{
	if (!globalIsJoystickUsed)
	{
		HANDLE handleStdInput;
		DWORD numberOfReaded, i;
		INPUT_RECORD inputRecordBuffer[128];
		BOOL cycleRun = true;
		
		handleStdInput = GetStdHandle(STD_INPUT_HANDLE);

		while(cycleRun)
		{
			if(ReadConsoleInput(handleStdInput, inputRecordBuffer, 128, &numberOfReaded))
			{
				for (i = 0; i < numberOfReaded; i++)
				{
					if (inputRecordBuffer[i].EventType==KEY_EVENT)
					{
						if (inputRecordBuffer[i].Event.KeyEvent.bKeyDown)
						{
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x25)
							{
								globalCursorPressed[0]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x26)
							{
								globalCursorPressed[1]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x27)
							{
								globalCursorPressed[2]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x28)
							{
								globalCursorPressed[3]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x51)
							{
								globalQAEDPressed[0]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x41)
							{
								globalQAEDPressed[1]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x45)
							{
								globalQAEDPressed[2]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x44)
							{
								globalQAEDPressed[3]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x31)
							{
								globalRobotDrivePowerLevel = 0;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x32)
							{
								globalRobotDrivePowerLevel = 1;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x33)
							{
								globalRobotDrivePowerLevel = 2;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x34)
							{
								globalRobotDrivePowerLevel = 3;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x35)
							{
								globalRobotDrivePowerLevel = 4;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x36)
							{
								globalRobotDrivePowerLevel = 5;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x37)
							{
								globalRobotDrivePowerLevel = 6;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x38)
							{
								globalRobotDrivePowerLevel = 7;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x39)
							{
								globalRobotDrivePowerLevel = 8;
							}
						}
						else
						{
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x25)
							{
								globalCursorPressed[0]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x26)
							{
								globalCursorPressed[1]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x27)
							{
								globalCursorPressed[2]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x28)
							{
								globalCursorPressed[3]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x51)
							{
								globalQAEDPressed[0]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x41)
							{
								globalQAEDPressed[1]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x45)
							{
								globalQAEDPressed[2]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x44)
							{
								globalQAEDPressed[3]=FALSE;
							}
						}
					}
				}
			}
		}
	}
}

VOID WINAPI ThreadProcedureCOMPortRead(PVOID*)
{
	DWORD bytesRead;
	BYTE readBuffer[128];
	WCHAR finalDataBuffer[128];
	ZeroMemory(&readBuffer, ARRAYSIZE(readBuffer));
	ZeroMemory(&finalDataBuffer, ARRAYSIZE(finalDataBuffer));

	COMSTAT comstat;
	DWORD mask=0;
	DWORD bytesInQue, numberOfBytesTransferred, error, signal;	

	ZeroMemory(&globalOverlapRead, sizeof(OVERLAPPED));
	globalOverlapRead.hEvent = CreateEvent(NULL, true, true, NULL);	
	SetCommMask(globalFileHandle, EV_RXCHAR);
	BOOL cycleRun = true;

	while(cycleRun)						
	{
		WaitCommEvent(globalFileHandle, &mask, &globalOverlapRead);              
		if (globalOverlapRead.hEvent != INVALID_HANDLE_VALUE && globalOverlapRead.hEvent != NULL)
		{
			signal = WaitForSingleObject(globalOverlapRead.hEvent, INFINITE);	
			if(signal == WAIT_OBJECT_0)				        
			{
				if(GetOverlappedResult(globalFileHandle, &globalOverlapRead, &numberOfBytesTransferred, true)) 
					if((mask & EV_RXCHAR)!=0)					
					{
						ClearCommError(globalFileHandle, &error, &comstat);		
						bytesInQue = comstat.cbInQue;                          	
						if(bytesInQue)                         			
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
	UINT joystickCounter=0;
	for(UINT i=0; i<=joyGetNumDevs(); i++) {
		if(joyGetDevCaps(i, &joycaps, sizeof(JOYCAPS))==JOYERR_NOERROR) {
			joystickCounter++;
			wprintf(TEXT("%u: %s with %u axes: ["),i,joycaps.szPname,joycaps.wNumAxes);
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
			wprintf(TEXT("] and %u buttons\n"), joycaps.wNumButtons);
		}
	}
	if (joystickCounter == 0)
	{
		wprintf(TEXT("We could not find any joystick devices.\n"));
	}
}

void enumeratingCOMPorts()
{
	wprintf(TEXT("\nEnumerating COM ports:\n"));
	UINT comPortCounter = 1;
	for (UINT i=1; i<256; i++)
	{
		WCHAR buffer[32];
		wsprintf(buffer,TEXT("\\\\.\\COM%u"), i);

		BOOL success = FALSE;
		globalFileHandle = CreateFile(buffer, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
		if (globalFileHandle == INVALID_HANDLE_VALUE)
		{
			DWORD lastError = GetLastError();
			if (lastError == ERROR_ACCESS_DENIED || lastError == ERROR_GEN_FAILURE || lastError == ERROR_SHARING_VIOLATION || lastError == ERROR_SEM_TIMEOUT)
				success = TRUE;
		}
		else
		{
			success = TRUE;
		}

		CloseHandle(globalFileHandle);
		if (success)
		{
			wprintf(TEXT("%u: COM%u\n"), comPortCounter, i);
			comPortCounter++;
		}
	}
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
	wprintf(TEXT("***************************************\n"));
	wprintf(TEXT("* www.robotics.by Tigger test utility *\n"));
	wprintf(TEXT("***************************************\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("Usage options:\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("tigger_joystick_module_test.exe [Joystick Number] [COM Port Name] [Baud Rate] [Use Keyboard]\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("Joystick Number - system number of joystick, usually from 0 to 15\n"));
	wprintf(TEXT("COM Port Name \t- COM Port Name like 'COM1'\n"));
	wprintf(TEXT("Baud Rate \t- COM Port baud rate like '9600'\n"));
	wprintf(TEXT("Use Keyboard \t- 'TRUE' or 'FALSE' to enable/disable keyboard support\n"));
	wprintf(TEXT("Keyboard active keys: \t\n"));
	wprintf(TEXT("'Q' and 'A' \t- left track control\n"));
	wprintf(TEXT("'E' and 'D' \t- right track control\n"));
	wprintf(TEXT("'ARROW UP' \t- move forward\n"));
	wprintf(TEXT("'ARROW DOWN' \t- move back\n"));
	wprintf(TEXT("'ARROW LEFT' \t- turn left\n"));
	wprintf(TEXT("'ARROW RIGHT' \t- turn right\n"));
	wprintf(TEXT("'1' - '9' \t- robot speed control\n"));
	enumeratingCOMPorts();
	enumeratingJoysticks();
}

int exitInformation()
{
	wprintf(TEXT("\nApplication will closed.\n"));
	wprintf(TEXT("\nPress 'Enter' key...\n"));
	return getchar();
}

int main(int argc, char** argv)
{
	setlocale(LC_CTYPE,"Russian");

	if (argc!=5)
	{
		usageInformation();
		exitInformation();
		return -1;
	}

	UINT joystickNumber = atoi(argv[1]);
	UINT baudRate = atoi(argv[3]);

	if (strcmp(argv[4],"TRUE") == 0)
	{
		globalIsJoystickUsed = FALSE;
	}
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

	wprintf(TEXT("Setting baud rate [%u]\n"),baudRate);

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

	dcb.BaudRate = baudRate;
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

	globalThreadCOMPortReadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcedureCOMPortRead, &globalThreadCOMPortReadParam, 0, &globalThreadCOMPortReadId);
	if (INVALID_HANDLE_VALUE == globalThreadCOMPortReadHandle)
	{
		CloseHandle(globalThreadCOMPortReadHandle);
		wprintf(TEXT("\nCreate Thread for COM Port Read issue.\n"));
		errorDetailedInformation(TEXT("CreateThread"));
		exitInformation();
		return -1;
	}

	globalThreadConsoleReadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProcedureConsoleRead, &globalThreadConsoleReadParam, 0, &globalThreadConsoleReadId);
	if (INVALID_HANDLE_VALUE == globalThreadConsoleReadHandle)
	{
		CloseHandle(globalThreadConsoleReadHandle);
		wprintf(TEXT("\nCreate Thread for Console Read issue.\n"));
		errorDetailedInformation(TEXT("CreateThread"));
		exitInformation();
		return -1;
	}

	if (globalIsJoystickUsed)
	{
		wprintf(TEXT("\nStart joystick aquire [%u]\n\n"),joystickNumber);
	}

	JOYINFOEX ji;

	ZeroMemory(&globalOverlapWrite, sizeof(OVERLAPPED));
	BOOL cycleRun = true;
	BYTE directRobotPowerValues[9]={142,156,170,184,198,212,226,240,255};
	BYTE inDirectRobotPowerValues[9]={112,98,84,70,56,42,28,14,0};

	while (cycleRun)
	{
		BYTE byteBuffer[10] = {'$',0,0,128,128,128,0,128,0,'#'};
		if (globalIsJoystickUsed)
		{		
			ZeroMemory(&ji, sizeof(JOYINFOEX));
			ji.dwSize = sizeof(JOYINFOEX);
			ji.dwFlags = JOY_RETURNALL;
			MMRESULT joystickFeadback = joyGetPosEx(joystickNumber, &ji);  

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

			byteBuffer[1] = ji.dwButtons&0xff;
			byteBuffer[2] = (ji.dwButtons>>8)&0xff;
			byteBuffer[3] = (ji.dwXpos>>8)&0xff;
			byteBuffer[4] = (ji.dwYpos>>8)&0xff;
			byteBuffer[5] = (ji.dwZpos>>8)&0xff;
			byteBuffer[6] = (ji.dwUpos>>8)&0xff;
			byteBuffer[7] = (ji.dwRpos>>8)&0xff;
			byteBuffer[8] = ((ji.dwPOV/4500)>>8)&0xff;
			if (byteBuffer[8]>7)
			{
				byteBuffer[8] = 8;
			}
		} else {
			if (globalQAEDPressed[0]==TRUE && globalQAEDPressed[1]==FALSE && globalQAEDPressed[2]==FALSE && globalQAEDPressed[3]==FALSE)
			{
				byteBuffer[4]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalQAEDPressed[0]==FALSE && globalQAEDPressed[1]==TRUE && globalQAEDPressed[2]==FALSE && globalQAEDPressed[3]==FALSE)
			{
				byteBuffer[4]=directRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalQAEDPressed[0]==FALSE && globalQAEDPressed[1]==FALSE && globalQAEDPressed[2]==TRUE && globalQAEDPressed[3]==FALSE)
			{
				byteBuffer[7]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalQAEDPressed[0]==FALSE && globalQAEDPressed[1]==FALSE && globalQAEDPressed[2]==FALSE && globalQAEDPressed[3]==TRUE)
			{
				byteBuffer[7]=directRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalQAEDPressed[0]==TRUE && globalQAEDPressed[1]==FALSE && globalQAEDPressed[2]==TRUE && globalQAEDPressed[3]==FALSE)
			{
				byteBuffer[4]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
				byteBuffer[7]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalQAEDPressed[0]==FALSE && globalQAEDPressed[1]==TRUE && globalQAEDPressed[2]==FALSE && globalQAEDPressed[3]==TRUE)
			{
				byteBuffer[4]=directRobotPowerValues[globalRobotDrivePowerLevel];
				byteBuffer[7]=directRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalQAEDPressed[0]==TRUE && globalQAEDPressed[1]==FALSE && globalQAEDPressed[2]==FALSE && globalQAEDPressed[3]==TRUE)
			{
				byteBuffer[4]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
				byteBuffer[7]=directRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalQAEDPressed[0]==FALSE && globalQAEDPressed[1]==TRUE && globalQAEDPressed[2]==TRUE && globalQAEDPressed[3]==FALSE)
			{
				byteBuffer[4]=directRobotPowerValues[globalRobotDrivePowerLevel];
				byteBuffer[7]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalCursorPressed[1]==TRUE)
			{
				byteBuffer[4]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
				byteBuffer[7]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalCursorPressed[3]==TRUE)
			{
				byteBuffer[4]=directRobotPowerValues[globalRobotDrivePowerLevel];
				byteBuffer[7]=directRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalCursorPressed[2]==TRUE)
			{
				byteBuffer[4]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
				byteBuffer[7]=directRobotPowerValues[globalRobotDrivePowerLevel];
			}
			if (globalCursorPressed[0]==TRUE)
			{
				byteBuffer[4]=directRobotPowerValues[globalRobotDrivePowerLevel];
				byteBuffer[7]=inDirectRobotPowerValues[globalRobotDrivePowerLevel];
			}
		}

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