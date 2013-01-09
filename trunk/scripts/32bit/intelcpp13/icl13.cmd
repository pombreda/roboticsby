if not exist "%ICPP_COMPILER13%\bin\iclvars.bat" goto missing
if not exist "%DXSDK_DIR%Include\d3d9.h" goto missingdxsdk
@"%ICPP_COMPILER13%bin\ipsxe-comp-vars.bat" ia32

:missing
@echo Intel C++ 13 not detected
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