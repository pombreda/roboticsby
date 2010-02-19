if not exist "%VS80COMNTOOLS%\vsvars32.bat" goto missing
if not exist "%DXSDK_DIR%Include\d3d9.h" goto missingdxsdk
@"%VS80COMNTOOLS%\vsvars32.bat"

:missing
@echo Microsoft Visual Studio 2005 not detected
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