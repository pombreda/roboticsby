if not exist "%ICPP_COMPILER11%\bin\ia32\iclvars_ia32.bat" goto missing
if not exist "%DXSDK_DIR%Include\d3d9.h" goto missingdxsdk
@"%ICPP_COMPILER11%\bin\ia32\iclvars_ia32.bat"

:missing
@echo Intel C++ 11 not detected
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