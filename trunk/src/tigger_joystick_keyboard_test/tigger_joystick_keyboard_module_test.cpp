/*
Copyright (C) 2013-2014, Sergey Gerasuto <contacts@robotics.by>

http://www.robotics.by/

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
- Neither the name of the RCSG Developers nor the names of its
contributors may be used to endorse or promote products derived from this
software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
`AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdio.h>
#include <windows.h>
#include <locale.h>
#include <wchar.h>
#include <math.h>
#include <vector>

HANDLE globalIncomingDataFileHandle = NULL;
HANDLE globalOutcomingDataFileHandle = NULL;
HANDLE globalFileHandle = NULL;
HANDLE globalThreadCOMPortReadHandle = NULL;
HANDLE globalThreadConsoleReadHandle = NULL;
HANDLE globalScryptFileHandle[] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
DWORD globalThreadCOMPortReadParam, globalThreadCOMPortReadId;
DWORD globalThreadConsoleReadParam, globalThreadConsoleReadId;
OVERLAPPED globalOverlapWrite, globalOverlapRead;
BOOL globalIsJoystickUsed = TRUE;
BOOL globalIsIncomingDataSaved = FALSE;
BOOL globalIsOutcomingDataSaved = FALSE;
BOOL globalQAEDPressed[] = {FALSE,FALSE,FALSE,FALSE};
BOOL globalCursorPressed[] = {FALSE,FALSE,FALSE,FALSE};
BOOL globalF1_12Pressed[] = {FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE};
char* globalRobotGUIDs[] = {
	"00000000-0000-0000-0000-000000000001","00000000-0000-0000-0000-000000000002","00000000-0000-0000-0000-000000000003","00000000-0000-0000-0000-000000000004",
	"00000000-0000-0000-0000-000000000005","00000000-0000-0000-0000-000000000006","00000000-0000-0000-0000-000000000007","00000000-0000-0000-0000-000000000008",
	"00000000-0000-0000-0000-000000000009","00000000-0000-0000-0000-000000000010","00000000-0000-0000-0000-000000000011","00000000-0000-0000-0000-000000000012"
};

double globalJoysticksConfig[3][8][6]= {
	{{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0}},// F510 Gamepad [XInput Mode]
	{{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0}},// USB Wireless 2.4GHz Gamepad
	{{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {-1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {1, 1, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}}// default;
};

BOOL globalGIBRPressed[]={FALSE};
USHORT globalRobotDrivePowerLevel = 0;
WCHAR globalCurrentExecutableDirectory[MAX_PATH];
BYTE globalRobotScriptIdentifier[] = {'<','r','o','b','o','t','s','c','r','i','p','t','>'};
DWORD globalTime = 0;
WORD  globalJoystickManufactureId = 0;
WORD  globalJoystickPlatformId = 0;

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

VOID clearRobotSelectedStatus()
{
	for (unsigned int i = 0; i<ARRAYSIZE(globalF1_12Pressed); i++)
	{
		globalF1_12Pressed[i] = FALSE;
	}
}

VOID WINAPI ThreadProcedureConsoleRead(PVOID*)
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
						if (!globalIsJoystickUsed)
						{
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
							{
								globalCursorPressed[0]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_UP)
							{
								globalCursorPressed[1]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_RIGHT)
							{
								globalCursorPressed[2]=TRUE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
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
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x47)
						{
							globalGIBRPressed[0]=TRUE;
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x49)
						{
							globalGIBRPressed[1]=TRUE;
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x42)
						{
							globalGIBRPressed[2]=TRUE;
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x52)
						{
							globalGIBRPressed[3]=TRUE;
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE)
						{
							clearRobotSelectedStatus();
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F1)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[0]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F2)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[1]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F3)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[2]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F4)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[3]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F5)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[4]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F6)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[5]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F7)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[6]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F8)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[7]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F9)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[8]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F10)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[9]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F11)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[10]=TRUE;	
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_F12)
						{
							clearRobotSelectedStatus();
							globalF1_12Pressed[11]=TRUE;	
						}
					}
					else
					{
						if (!globalIsJoystickUsed)
						{
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
							{
								globalCursorPressed[0]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_UP)
							{
								globalCursorPressed[1]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_RIGHT)
							{
								globalCursorPressed[2]=FALSE;
							}
							if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_DOWN)
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
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x47)
						{
							globalGIBRPressed[0]=FALSE;
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x49)
						{
							globalGIBRPressed[1]=FALSE;
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x42)
						{
							globalGIBRPressed[2]=FALSE;
						}
						if (inputRecordBuffer[i].Event.KeyEvent.wVirtualKeyCode == 0x52)
						{
							globalGIBRPressed[3]=FALSE;
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
								if (globalIsIncomingDataSaved!=FALSE)
								{
									if (globalIncomingDataFileHandle != INVALID_HANDLE_VALUE)
									{
										DWORD bytesIncomingDataWrite;
										WriteFile(globalIncomingDataFileHandle, readBuffer, bytesRead, &bytesIncomingDataWrite, NULL);
										FlushFileBuffers(globalIncomingDataFileHandle);
									}
								}
								ZeroMemory(&readBuffer, ARRAYSIZE(readBuffer));
								ZeroMemory(&finalDataBuffer, ARRAYSIZE(finalDataBuffer));
							}                      		
						}
					}
			}
		}
	}
}

VOID enumeratingJoysticks()
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

VOID enumeratingCOMPorts()
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

LPCWSTR multiCharToUniChar(char* charBuffer, WCHAR* wCharBuffer)
{ 
	size_t len = strlen(charBuffer) + 1; 
	size_t reqsize = 0;
	mbstowcs_s(&reqsize, NULL, 0, charBuffer, len);
	if(!reqsize) return NULL;
	mbstowcs_s(NULL, &wCharBuffer[0], len, charBuffer, len);
	return (LPCWSTR)wCharBuffer; 
}

void displaySendedToRobotInformation(const BYTE *information, unsigned int arraySize)
{
	wprintf(TEXT("Sending to robot's: ["));
	for (unsigned int i=0; i<arraySize; i++)
	{
		if (i == arraySize-1)
		{
			wprintf(TEXT("%02X"), information[i]);
		} else 
		{
			wprintf(TEXT("%02X "), information[i]);
		}
	}
	wprintf(TEXT("]\n"));
}

BYTE correctPowerValues(BYTE value)
{
	BYTE powerValues[]={0,14,28,42,56,70,84,98,128,156,170,184,198,212,226,240,255};
	BYTE maxValue = powerValues[0];
	for (int i=0; i<ARRAYSIZE(powerValues); i++)
	{
		if (value==powerValues[i]) return value;
		if (sqrt((double)(value*value+powerValues[i]*powerValues[i]))>sqrt((double)(maxValue*maxValue+powerValues[i]*powerValues[i]))) maxValue=powerValues[i];
	}
	return maxValue;
}

BOOL updateToSelectedRobotGUID(BYTE* extendedByteBuffer)
{
	char* guid = NULL;

	if (globalF1_12Pressed[0]!=FALSE)
	{
		guid = globalRobotGUIDs[0]; 
	}
	if (globalF1_12Pressed[1]!=FALSE)
	{
		guid = globalRobotGUIDs[1]; 
	}
	if (globalF1_12Pressed[2]!=FALSE)
	{
		guid = globalRobotGUIDs[2]; 
	}
	if (globalF1_12Pressed[3]!=FALSE)
	{
		guid = globalRobotGUIDs[3]; 
	}
	if (globalF1_12Pressed[4]!=FALSE)
	{
		guid = globalRobotGUIDs[4]; 
	}
	if (globalF1_12Pressed[5]!=FALSE)
	{
		guid = globalRobotGUIDs[5]; 
	}
	if (globalF1_12Pressed[6]!=FALSE)
	{
		guid = globalRobotGUIDs[6]; 
	}
	if (globalF1_12Pressed[7]!=FALSE)
	{
		guid = globalRobotGUIDs[7]; 
	}
	if (globalF1_12Pressed[8]!=FALSE)
	{
		guid = globalRobotGUIDs[8]; 
	}
	if (globalF1_12Pressed[9]!=FALSE)
	{
		guid = globalRobotGUIDs[9]; 
	}
	if (globalF1_12Pressed[10]!=FALSE)
	{
		guid = globalRobotGUIDs[10]; 
	}
	if (globalF1_12Pressed[11]!=FALSE)
	{
		guid = globalRobotGUIDs[11]; 
	}

	if (guid!=NULL)
	{
		for (unsigned int i = 0; i<36; i++)
		{
			extendedByteBuffer[1+i] = guid[i];
		}
		return TRUE;
	}

	return FALSE;
}

void usageInformation()
{
	wprintf(TEXT("***************************************\n"));
	wprintf(TEXT("* www.robotics.by Tigger test utility *\n"));
	wprintf(TEXT("***************************************\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("Usage options:\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("tigger_joystick_module_test.exe [Joystick Number] [COM Port Name] [Baud Rate] [Use Keyboard] [Logging Incoming Data] [Logging Outcoming Data]\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("Sript mode:\n"));
	wprintf(TEXT("\n"));
	wprintf(TEXT("tigger_joystick_module_test.exe script [1-12] [COM Port Name] [Baud Rate]\n"));
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
	wprintf(TEXT("Incoming data \t- 'TRUE' or 'FALSE' to enable/disable logging. A 'robotin.txt' file will created in the same folder as executable.\n"));
	wprintf(TEXT("Outcoming data \t- 'TRUE' or 'FALSE' to enable/disable logging. A 'robotout.txt' file will created in the same folder as executable.\n"));
	enumeratingCOMPorts();
	enumeratingJoysticks();
}

int exitInformation()
{
	wprintf(TEXT("\nApplication will closed.\n"));
	wprintf(TEXT("\nPress 'Enter' key...\n"));
	return getchar();
}

DWORD getFileSize(LPCWSTR fileName)
{
	WIN32_FILE_ATTRIBUTE_DATA   fileInfo;
	if (NULL == fileName)
		return 0;
	if (!GetFileAttributesEx(fileName, GetFileExInfoStandard, &fileInfo))
		return 0;
	return fileInfo.nFileSizeLow;
}

int scryptPlayer(int argc, char** argv)
{
	if (argc!=5)
		return -1;

	UINT scriptFilesCount = atoi(argv[2]);

	if (scriptFilesCount<1 || scriptFilesCount>12)
	{
		wprintf(TEXT("\nNumber of script files out of range [1-12].\n"));
		exitInformation();
		return -1;
	}

	DWORD fileSizeRobotScrypt[] = {0,0,0,0,0,0,0,0,0,0,0,0};

	for(UINT i=0;i<scriptFilesCount;i++)
	{
		{
			OPENFILENAME openFileName;      
			WCHAR fileBuffer[MAX_PATH];      
			HWND windowHandle = NULL;             

			ZeroMemory(&openFileName, sizeof(openFileName));
			openFileName.lStructSize = sizeof(OPENFILENAME);
			openFileName.hwndOwner = windowHandle;
			openFileName.lpstrFile = fileBuffer;
			openFileName.lpstrFile[0] = '\0';
			openFileName.nMaxFile = sizeof(fileBuffer);
			openFileName.lpstrFilter = L"All\0*.*\0Text\0*.robotscript\0";
			openFileName.nFilterIndex = 1;
			openFileName.lpstrFileTitle = NULL;
			openFileName.nMaxFileTitle = 0;
			openFileName.lpstrInitialDir = NULL;
			openFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetOpenFileName(&openFileName)==TRUE) 
				globalScryptFileHandle[i] = CreateFile(openFileName.lpstrFile, 
				GENERIC_READ,
				0,
				(LPSECURITY_ATTRIBUTES) NULL,
				OPEN_EXISTING,
				FILE_ATTRIBUTE_NORMAL,
				(HANDLE) NULL);

			if (NULL != globalScryptFileHandle)
			{
				fileSizeRobotScrypt[i] = getFileSize(openFileName.lpstrFile);
			}
		}

		if (NULL == globalScryptFileHandle[i] && fileSizeRobotScrypt[i]>ARRAYSIZE(globalRobotScriptIdentifier) && fileSizeRobotScrypt[i]<100*1024*1024)
		{
			wprintf(TEXT("\nUnable to use '*.robotscript' file.\n"));
			errorDetailedInformation(TEXT("CreateFile"));
			exitInformation();
			return -1;
		}
	}

	UINT baudRate = atoi(argv[4]);

	WCHAR wBuffer[512];
	char buffer[32];
	sprintf_s(buffer,"\\\\.\\%s", argv[3]);

	wprintf(TEXT("Opening port [%s]\n"),multiCharToUniChar(buffer, wBuffer));
	globalFileHandle = CreateFile(multiCharToUniChar(buffer,wBuffer), GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
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

	BOOL cycleRun = true;
	BYTE *scryptFileMemoryBuffer []= {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	for(UINT i=0;i<scriptFilesCount;i++)
	{
		scryptFileMemoryBuffer[i] = (BYTE*)HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,fileSizeRobotScrypt[i]);
		DWORD nRead;
		if (globalScryptFileHandle[i]!=NULL)
		{
			if (ReadFile(globalScryptFileHandle[i],scryptFileMemoryBuffer[i],fileSizeRobotScrypt[i],&nRead,NULL))
			{
				CloseHandle(globalScryptFileHandle[i]);
			} else
			{
				CloseHandle(globalScryptFileHandle[i]);
				wprintf(TEXT("\nUnable to read '*.robotscript' file.\n"));
				errorDetailedInformation(TEXT("ReadFile"));
				exitInformation();
				return -1;
			}	
		} else {
			wprintf(TEXT("\nUnable to use file handle of '*.robotscript' file.\n"));
			exitInformation();
			return -1;
		}

		if ((nRead<ARRAYSIZE(globalRobotScriptIdentifier)) || (memcmp(scryptFileMemoryBuffer[i],globalRobotScriptIdentifier,ARRAYSIZE(globalRobotScriptIdentifier))!=0))
		{
			wprintf(TEXT("\nUnable to use '*.robotscript' file.\n"));
			exitInformation();
			return -1;
		}
	}

	std::vector<std::pair<DWORD,DWORD>> script[ARRAYSIZE(fileSizeRobotScrypt)];

	for(UINT j=0;j<scriptFilesCount;j++)
	{
		DWORD scriptCounter = ARRAYSIZE(globalRobotScriptIdentifier);
		DWORD first = scriptCounter;
		while (scriptCounter<fileSizeRobotScrypt[j])
		{
			BYTE comparationBuffer[ARRAYSIZE(globalRobotScriptIdentifier)];
			ZeroMemory(&comparationBuffer,ARRAYSIZE(globalRobotScriptIdentifier));
			for(DWORD i=0;i<ARRAYSIZE(globalRobotScriptIdentifier);i++)
			{
				if (i+scriptCounter<fileSizeRobotScrypt[j])
				{
					comparationBuffer[i]=scryptFileMemoryBuffer[j][i+scriptCounter];
				}
			}
			if (memcmp(comparationBuffer,globalRobotScriptIdentifier,ARRAYSIZE(globalRobotScriptIdentifier))==0)
			{
				std::pair<DWORD,DWORD> scriptPair;
				scriptPair.first = first;
				scriptPair.second = scriptCounter;
				script[j].push_back(scriptPair);
				scriptCounter+=ARRAYSIZE(globalRobotScriptIdentifier);
				first=scriptCounter;
				continue;
			}
			scriptCounter++;
			if (scriptCounter==fileSizeRobotScrypt[j]-1)
			{
				std::pair<DWORD,DWORD> scriptPair;
				scriptPair.first = first;
				scriptPair.second = fileSizeRobotScrypt[j];
				script[j].push_back(scriptPair);
			}
		}
	}

	wprintf(TEXT("\nStarting robot script playing...\n"));

	while (cycleRun)
	{
		globalTime = timeGetTime();
		for(UINT j=0;j<scriptFilesCount;j++)
		{
			if (script[j].size()>0)
			{
				std::pair<DWORD,DWORD> scriptPair = script[j].front();
				script[j].erase(script[j].begin());
				BYTE *commandBuffer = new BYTE[scriptPair.second-scriptPair.first];
				for(DWORD i=0;i<scriptPair.second-scriptPair.first;i++)
				{
					commandBuffer[i]=scryptFileMemoryBuffer[j][i+scriptPair.first];
				}
				DWORD bytesWrite;
				WriteFile(globalFileHandle, commandBuffer, scriptPair.second-scriptPair.first, &bytesWrite, &globalOverlapWrite);
				FlushFileBuffers(globalFileHandle);
				displaySendedToRobotInformation(commandBuffer, scriptPair.second-scriptPair.first);
				delete[] commandBuffer;
			}
		}
		while ((globalTime+100)>timeGetTime())
		{
			Sleep(1);
		}
		globalTime = timeGetTime();

		cycleRun = FALSE;
		for(UINT j=0;j<scriptFilesCount;j++)
		{
			if (script[j].size()>0)
			{
				cycleRun = TRUE;
			}
		}
	}

	for(UINT j = 0;j<scriptFilesCount;j++)
	{
		HeapFree(GetProcessHeap(),0,scryptFileMemoryBuffer[j]);
	}	
	CloseHandle(globalFileHandle);
	return -1;
}

int main(int argc, char** argv)
{
	setlocale(LC_CTYPE,"Russian");

	{
		DWORD currentDirectoryPathLen = 0;
		currentDirectoryPathLen = GetCurrentDirectory(MAX_PATH, globalCurrentExecutableDirectory);
		if (currentDirectoryPathLen < 1)
		{
			wprintf(TEXT("\nGetting current directory issue.\n"));
			errorDetailedInformation(TEXT("GetCurrentDirectory"));
			exitInformation();
			return -1;
		}
	}

	if (argc!=7)
	{
		if (argc==5) 
		{
			if (strcmp(argv[1],"script") == 0)
			{
				return scryptPlayer(argc, argv);
			}
		}
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

	if (strcmp(argv[5],"TRUE") == 0)
	{
		globalIsIncomingDataSaved = TRUE;
		WCHAR filePath[MAX_PATH];
		ZeroMemory(&filePath, ARRAYSIZE(filePath));
		wsprintf(filePath,TEXT("%s\\%s"), globalCurrentExecutableDirectory, TEXT("robotin.txt"));
		globalIncomingDataFileHandle = CreateFile(filePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (INVALID_HANDLE_VALUE == globalIncomingDataFileHandle)
		{
			CloseHandle(globalIncomingDataFileHandle);
			wprintf(TEXT("\nUnable to create 'robotin.txt' file.\n"));
			errorDetailedInformation(TEXT("CreateFile"));
			exitInformation();
			return -1;
		}
	}

	if (strcmp(argv[6],"TRUE") == 0)
	{
		globalIsOutcomingDataSaved = TRUE;
		WCHAR filePath[MAX_PATH];
		ZeroMemory(&filePath, ARRAYSIZE(filePath));
		wsprintf(filePath,TEXT("%s\\%s"), globalCurrentExecutableDirectory, TEXT("robotout.txt"));
		globalOutcomingDataFileHandle = CreateFile(filePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (INVALID_HANDLE_VALUE == globalOutcomingDataFileHandle)
		{
			CloseHandle(globalOutcomingDataFileHandle);
			wprintf(TEXT("\nUnable to create 'robotout.txt' file.\n"));
			errorDetailedInformation(TEXT("CreateFile"));
			exitInformation();
			return -1;
		}
	}

	WCHAR wBuffer[512];
	char buffer[32];
	sprintf_s(buffer,"\\\\.\\%s", argv[2]);

	wprintf(TEXT("Opening port [%s]\n"),multiCharToUniChar(buffer, wBuffer));
	globalFileHandle = CreateFile(multiCharToUniChar(buffer,wBuffer), GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
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
		JOYCAPS joystickCapacites;
		ZeroMemory(&joystickCapacites,sizeof(JOYCAPS));
		joyGetDevCaps(joystickNumber, &joystickCapacites, sizeof(JOYCAPS));
		globalJoystickManufactureId = joystickCapacites.wMid;
		globalJoystickPlatformId = joystickCapacites.wPid;
	}

	JOYINFOEX ji;

	ZeroMemory(&globalOverlapWrite, sizeof(OVERLAPPED));
	BOOL cycleRun = true;
	BYTE directRobotPowerValues[]={142,156,170,184,198,212,226,240,255};
	BYTE inDirectRobotPowerValues[]={112,98,84,70,56,42,28,14,0};

	while (cycleRun)
	{
		globalTime = timeGetTime();
		BYTE byteBuffer[] = {'$',0,0,128,128,128,0,128,0,'#'};
		BYTE extendedByteBuffer[]={'$','0','0','0','0','0','0','0','0','-','0','0','0','0','-','0','0','0','0','-','0','0','0','0','-','0','0','0','0','0','0','0','0','0','0','0','0','c','t','r','l','$',0,0,128,128,128,0,128,0,'#'};
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
				CloseHandle(globalIncomingDataFileHandle);
				CloseHandle(globalOutcomingDataFileHandle);
				errorDetailedInformation(TEXT("joyGetPosEx"));
				exitInformation();
				return -1;
			}

			UINT joysticksConfigNumber = ARRAYSIZE(globalJoysticksConfig)-1;
			
			if (globalJoystickManufactureId==1133 && globalJoystickPlatformId==49694)
			{
				joysticksConfigNumber = 0;
			} else if (globalJoystickManufactureId==3727 && globalJoystickPlatformId==18)
			{
				joysticksConfigNumber = 1;
			}
			
			double joysticksConfigVector[6] = {(double)((ji.dwXpos>>8)&0xff)-128, (double)((ji.dwYpos>>8)&0xff)-128, (double)((ji.dwZpos>>8)&0xff)-128, (double)((ji.dwUpos>>8)&0xff)-128, (double)((ji.dwRpos>>8)&0xff)-128, (double)((ji.dwVpos>>8)&0xff)-128};
			for (UINT joysticksConfigI=0; joysticksConfigI<8; joysticksConfigI++)
			{
				double joysticksConfigResult = 0;
				for (UINT joysticksConfigJ=0; joysticksConfigJ<6; joysticksConfigJ++)
					joysticksConfigResult+=globalJoysticksConfig[joysticksConfigNumber][joysticksConfigI][joysticksConfigJ]*joysticksConfigVector[joysticksConfigJ];
				joysticksConfigResult+=128;
				if (joysticksConfigResult<0)
					joysticksConfigResult=0;
				if (joysticksConfigResult>255)
					joysticksConfigResult=255;
				byteBuffer[joysticksConfigI+1]=correctPowerValues((BYTE)(joysticksConfigResult+0.5));
			}
			byteBuffer[1] = 0;
			byteBuffer[2] = 0;
			byteBuffer[8] = 0;
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

		BOOL robotGUIDControl = updateToSelectedRobotGUID(extendedByteBuffer); 

		if (robotGUIDControl!=FALSE)
		{
			unsigned int byteBufferCounter=0;
			for (unsigned int i = (ARRAYSIZE(extendedByteBuffer)-ARRAYSIZE(byteBuffer));i<ARRAYSIZE(extendedByteBuffer);i++)
			{
				extendedByteBuffer[i]=byteBuffer[byteBufferCounter];
				byteBufferCounter++;
			}

			WriteFile(globalFileHandle, extendedByteBuffer, ARRAYSIZE(extendedByteBuffer), &bytesWrite, &globalOverlapWrite);
			FlushFileBuffers(globalFileHandle);

			if (globalIsOutcomingDataSaved!=FALSE)
			{
				if (globalOutcomingDataFileHandle != INVALID_HANDLE_VALUE)
				{
					DWORD bytesOutcomingDataWrite;
					WriteFile(globalOutcomingDataFileHandle, globalRobotScriptIdentifier,  ARRAYSIZE(globalRobotScriptIdentifier), &bytesOutcomingDataWrite, NULL);
					WriteFile(globalOutcomingDataFileHandle, extendedByteBuffer, ARRAYSIZE(extendedByteBuffer), &bytesOutcomingDataWrite, NULL);
					FlushFileBuffers(globalOutcomingDataFileHandle);
				}
			}

			if (globalGIBRPressed[0]==TRUE)
			{
				BYTE commandBuffer[]={'$','g','e','t','G','U','I','D','#'};
				WriteFile(globalFileHandle, commandBuffer, ARRAYSIZE(commandBuffer), &bytesWrite, &globalOverlapWrite);
				FlushFileBuffers(globalFileHandle);

				if (globalIsOutcomingDataSaved!=FALSE)
				{
					if (globalOutcomingDataFileHandle != INVALID_HANDLE_VALUE)
					{
						DWORD bytesOutcomingDataWrite;
						WriteFile(globalOutcomingDataFileHandle, globalRobotScriptIdentifier,  ARRAYSIZE(globalRobotScriptIdentifier), &bytesOutcomingDataWrite, NULL);
						WriteFile(globalOutcomingDataFileHandle, commandBuffer,  ARRAYSIZE(commandBuffer), &bytesOutcomingDataWrite, NULL);
						FlushFileBuffers(globalOutcomingDataFileHandle);
					}
				}
				displaySendedToRobotInformation(commandBuffer, ARRAYSIZE(commandBuffer));
			}

			if (globalGIBRPressed[1]==TRUE)
			{
				BYTE commandBuffer[]={'$','0','0','0','0','0','0','0','0','-','0','0','0','0','-','0','0','0','0','-','0','0','0','0','-','0','0','0','0','0','0','0','0','0','0','0','0','g','e','t','I','n','f','o','r','m','a','t','i','o','n','#'};
				if (updateToSelectedRobotGUID(commandBuffer))
				{
					WriteFile(globalFileHandle, commandBuffer, ARRAYSIZE(commandBuffer), &bytesWrite, &globalOverlapWrite);
					FlushFileBuffers(globalFileHandle);

					if (globalIsOutcomingDataSaved!=FALSE)
					{
						if (globalOutcomingDataFileHandle != INVALID_HANDLE_VALUE)
						{
							DWORD bytesOutcomingDataWrite;
							WriteFile(globalOutcomingDataFileHandle, globalRobotScriptIdentifier,  ARRAYSIZE(globalRobotScriptIdentifier), &bytesOutcomingDataWrite, NULL);
							WriteFile(globalOutcomingDataFileHandle, commandBuffer,  ARRAYSIZE(commandBuffer), &bytesOutcomingDataWrite, NULL);
							FlushFileBuffers(globalOutcomingDataFileHandle);
						}
					}
					displaySendedToRobotInformation(commandBuffer, ARRAYSIZE(commandBuffer));
				}
			}

			if (globalGIBRPressed[2]==TRUE)
			{
				BYTE commandBuffer[]={'$','0','0','0','0','0','0','0','0','-','0','0','0','0','-','0','0','0','0','-','0','0','0','0','-','0','0','0','0','0','0','0','0','0','0','0','0','g','e','t','B','a','t','t','e','r','y','V','o','l','t','a','g','e','#'};
				if (updateToSelectedRobotGUID(commandBuffer))
				{
					WriteFile(globalFileHandle, commandBuffer, ARRAYSIZE(commandBuffer), &bytesWrite, &globalOverlapWrite);
					FlushFileBuffers(globalFileHandle);

					if (globalIsOutcomingDataSaved!=FALSE)
					{
						if (globalOutcomingDataFileHandle != INVALID_HANDLE_VALUE)
						{
							DWORD bytesOutcomingDataWrite;
							WriteFile(globalOutcomingDataFileHandle, globalRobotScriptIdentifier,  ARRAYSIZE(globalRobotScriptIdentifier), &bytesOutcomingDataWrite, NULL);
							WriteFile(globalOutcomingDataFileHandle, commandBuffer,  ARRAYSIZE(commandBuffer), &bytesOutcomingDataWrite, NULL);
							FlushFileBuffers(globalOutcomingDataFileHandle);
						}
					}
					displaySendedToRobotInformation(commandBuffer, ARRAYSIZE(commandBuffer));
				}
			}

			if (globalGIBRPressed[3]==TRUE)
			{
				BYTE commandBuffer[]={'$','0','0','0','0','0','0','0','0','-','0','0','0','0','-','0','0','0','0','-','0','0','0','0','-','0','0','0','0','0','0','0','0','0','0','0','0','g','e','t','R','S','S','I','#'};
				if (updateToSelectedRobotGUID(commandBuffer))
				{
					WriteFile(globalFileHandle, commandBuffer, ARRAYSIZE(commandBuffer), &bytesWrite, &globalOverlapWrite);
					FlushFileBuffers(globalFileHandle);

					if (globalIsOutcomingDataSaved!=FALSE)
					{
						if (globalOutcomingDataFileHandle != INVALID_HANDLE_VALUE)
						{
							DWORD bytesOutcomingDataWrite;
							WriteFile(globalOutcomingDataFileHandle, globalRobotScriptIdentifier,  ARRAYSIZE(globalRobotScriptIdentifier), &bytesOutcomingDataWrite, NULL);
							WriteFile(globalOutcomingDataFileHandle, commandBuffer,  ARRAYSIZE(commandBuffer), &bytesOutcomingDataWrite, NULL);
							FlushFileBuffers(globalOutcomingDataFileHandle);
						}
					}
					displaySendedToRobotInformation(commandBuffer, ARRAYSIZE(commandBuffer));
				}
			}
			displaySendedToRobotInformation(extendedByteBuffer, ARRAYSIZE(extendedByteBuffer));
		} 
		else 
		{
			WriteFile(globalFileHandle, byteBuffer, ARRAYSIZE(byteBuffer), &bytesWrite, &globalOverlapWrite);
			FlushFileBuffers(globalFileHandle);

			if (globalIsOutcomingDataSaved!=FALSE)
			{
				if (globalOutcomingDataFileHandle != INVALID_HANDLE_VALUE)
				{
					DWORD bytesOutcomingDataWrite;
					WriteFile(globalOutcomingDataFileHandle, globalRobotScriptIdentifier,  ARRAYSIZE(globalRobotScriptIdentifier), &bytesOutcomingDataWrite, NULL);
					WriteFile(globalOutcomingDataFileHandle, byteBuffer, ARRAYSIZE(byteBuffer), &bytesOutcomingDataWrite, NULL);
					FlushFileBuffers(globalOutcomingDataFileHandle);
				}
			}

			if (globalGIBRPressed[0]==TRUE)
			{
				BYTE commandBuffer[]={'$','g','e','t','G','U','I','D','#'};
				WriteFile(globalFileHandle, commandBuffer, ARRAYSIZE(commandBuffer), &bytesWrite, &globalOverlapWrite);
				FlushFileBuffers(globalFileHandle);

				if (globalIsOutcomingDataSaved!=FALSE)
				{
					if (globalOutcomingDataFileHandle != INVALID_HANDLE_VALUE)
					{
						DWORD bytesOutcomingDataWrite;
						WriteFile(globalOutcomingDataFileHandle, globalRobotScriptIdentifier,  ARRAYSIZE(globalRobotScriptIdentifier), &bytesOutcomingDataWrite, NULL);
						WriteFile(globalOutcomingDataFileHandle, commandBuffer,  ARRAYSIZE(commandBuffer), &bytesOutcomingDataWrite, NULL);
						FlushFileBuffers(globalOutcomingDataFileHandle);
					}
				}
				displaySendedToRobotInformation(commandBuffer, ARRAYSIZE(commandBuffer));
			}

			displaySendedToRobotInformation(byteBuffer, ARRAYSIZE(byteBuffer));
		}
		while ((globalTime+100)>timeGetTime())
		{
			Sleep(1);
		}
		globalTime = timeGetTime();
	}
}