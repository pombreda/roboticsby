#include <windows.h>
#include <iostream>
#include "system_information_detection_module\system_information_detection_module.h"

#define BUFFER_SIZE 1024
#define BUFFER_COUNT 16
wchar_t text_buf[BUFFER_COUNT][BUFFER_SIZE];
INT buffer_count;
BOOL need_paint;

LRESULT CALLBACK WindProcedure(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

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
				wsprintf(text_buf[buffer_count], L"%s", L"ModuleInformation\n");
				buffer_count++;
				wsprintf(text_buf[buffer_count], L"Module Version: %d\n\n",s.moduleVersion);
				buffer_count++;
				buffer_count++;
			}
		}
		else 
		{
			wsprintf(text_buf[buffer_count], L"Error Load function\n");
			buffer_count++;
		}
		::FreeLibrary(hModule); 
	}
	else 
	{
		wsprintf(text_buf[buffer_count], L"Error load dll");
		buffer_count++;
	}
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
				wsprintf(text_buf[buffer_count], L"SystemInformation\n");
				buffer_count++;
				wsprintf(text_buf[buffer_count], L"OS: Windows %ld.%ld.%ld\n",s.osVersion.dwMajorVersion,s.osVersion.dwMinorVersion,s.osVersion.dwBuildNumber);
				buffer_count++;
				wsprintf(text_buf[buffer_count], L"Memory: %ldK total, %ldK free\n",s.memoryStatus.dwTotalPhys/1024L,s.memoryStatus.dwAvailPhys/1024L);
				buffer_count++;
				if (s.isHostRunningOnBatteries) wsprintf(text_buf[buffer_count], L"Power status: %s\n",L"Battery");
				else wsprintf(text_buf[buffer_count], L"Power status: %s\n",L"AC");
				buffer_count++;
				wsprintf(text_buf[buffer_count], L"Number of available processors: %d\n",s.processorCount);
				buffer_count++;
				wsprintf(text_buf[buffer_count], L"DirectX version string: %s\n",s.strDirectXVersion);
				buffer_count++;
				wsprintf(text_buf[buffer_count], L"DirectX version hex number: %x\n",s.dwDirectXVersion);
				buffer_count++;
			}
		}
		else 
		{
			wsprintf(text_buf[buffer_count], L"Error Load function\n");
			buffer_count++;
		}
		::FreeLibrary(hModule); 
	}
	else 
	{
		wsprintf(text_buf[buffer_count], L"Error load dll");
		buffer_count++;
	}
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX  WndCls;
    MSG         Msg;

    WndCls.cbSize        = sizeof(WndCls);
    WndCls.style         = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
    WndCls.lpfnWndProc   = WindProcedure;
    WndCls.cbClsExtra    = 0;
    WndCls.cbWndExtra    = 0;
    WndCls.hInstance     = hInstance;
    WndCls.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    WndCls.hCursor       = LoadCursor(NULL, IDC_ARROW);
    WndCls.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    WndCls.lpszMenuName  = NULL;
    WndCls.lpszClassName = L"System information detection module test";
    WndCls.hIconSm       = LoadIcon(hInstance, IDI_APPLICATION);
    RegisterClassEx(&WndCls);

    CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,
                          L"System information detection module test",
                          L"System information detection module test",
                          WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    while( GetMessage(&Msg, NULL, 0, 0) )
    {
        TranslateMessage(&Msg);
        DispatchMessage( &Msg);
    }

    return static_cast<INT>(Msg.wParam);
}

LRESULT CALLBACK WindProcedure(HWND hWnd, UINT Msg,
			   WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
         PAINTSTRUCT Ps;

	switch(Msg)
	{
	case WM_SIZE:
		need_paint = true;
		break;
	case WM_CREATE:
		buffer_count = 0;
		showModuleInformation();
		showSystemInformation();
		need_paint = true;
		break;
	case WM_DESTROY:
		PostQuitMessage(WM_QUIT);
		break;
	case WM_PAINT:
		if (need_paint)
		{
		hDC = BeginPaint(hWnd, &Ps);
			for (INT i=0; i<buffer_count; i++)
			{
				TextOut(hDC, 0, 0+i*16, text_buf[i], BUFFER_SIZE);
			}
		EndPaint(hWnd, &Ps);
		need_paint = false;
		}
		break;
	default:
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}
	return 0;
}