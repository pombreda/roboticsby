@echo off
@echo *********************************
@echo * Roboticsby Build creator      * 
@echo *********************************
@echo Progress: Build Started using MVS 2005

call 32bit\vs2005\cl2005.cmd
cl /EHsc /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /arch:SSE2 /O1 /analyze ..\src\system_information_detection_module_test.cpp
cl /EHsc /D "_UNICODE" /D "UNICODE" /arch:SSE2  /D "WIN32" /D "_WINDOWS" /O1 /analyze ..\src\system_information_detection_module_test_win.cpp /link user32.lib gdi32.lib kernel32.lib 
cl /EHsc /D "_UNICODE" /D "UNICODE" /arch:SSE2 /LD /O1 -I"%DXSDK_DIR%Include" /analyze ..\src\system_information_detection_module\system_information_detection_module.cpp  /link /LIBPATH:"%DXSDK_DIR%Lib\x86\"  Version.lib dxguid.lib  kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib

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