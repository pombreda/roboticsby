@echo off
@echo *********************************
@echo * Roboticsby Build creator      * 
@echo *********************************
@echo Progress: Build Started using MVS 2005

call 32bit\vs2005\cl2005.cmd
cl /EHsc /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /arch:SSE2 /O2 ..\src\system_information_detection_module_test.cpp
cl /EHsc /D "_UNICODE" /D "UNICODE" /arch:SSE2 /LD /O2 ..\src\system_information_detection_module\system_information_detection_module.cpp

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