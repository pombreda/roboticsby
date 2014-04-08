@echo off
@echo *********************************
@echo * www.robotics.by Build creator * 
@echo *********************************
@echo Progress: Build Started using Intel C++ 12

call 32bit\intelcpp12\icl12.cmd
icl /EHsc /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /arch:SSE2 /O1 ..\src\tigger_joystick_keyboard_test\tigger_joystick_keyboard_module_test.cpp /link Winmm.lib user32.lib Comdlg32.lib
icl /EHsc /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /arch:SSE2 /O1 ..\src\system_information_detection_module\system_information_detection_module_test.cpp
icl /EHsc /D "_UNICODE" /D "UNICODE" /arch:SSE2  /D "WIN32" /D "_WINDOWS" /O1 ..\src\system_information_detection_module\system_information_detection_module_test_win.cpp /link user32.lib gdi32.lib kernel32.lib 
icl /EHsc /D "_UNICODE" /D "UNICODE" /arch:SSE2 /LD /O1 -I"%DXSDK_DIR%Include" ..\src\system_information_detection_module\system_information_detection_module.cpp ..\src\system_information_detection_module\gpu_information.cpp ..\src\system_information_detection_module\cpu_information.cpp ..\src\system_information_detection_module\directx_information.cpp /link /LIBPATH:"%DXSDK_DIR%Lib\x86\"  Version.lib dxguid.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib

@echo Progress: Build Ended
@echo Progress: File copying operations
@xcopy /s *.exe ..\bin
@xcopy /s *.dll ..\bin
@echo Progress: Delete temporary files
@del *.exe
@del *.dll
@del *.obj
@del *.lib
@del *.exp
@echo Progress: All operations finished
@pause
@echo on