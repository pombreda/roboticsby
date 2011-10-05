if not exist "%ICPP_COMPILER12%\bin\iclvars.bat" goto missing
if not exist "%DXSDK_DIR%Include\d3d9.h" goto missingdxsdk
@"%ICPP_COMPILER12%bin\ipsxe-comp-vars.bat" ia32

:missing
@echo Intel C++ 12 not detected
@pause
@echo on
@exit
goto :eof

:missingdxsdk
@echo Microsoft DirectX SDK not detected
@pause
@echo on
@exit
goto :eof