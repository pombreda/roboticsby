if not exist "%VS110COMNTOOLS%\vsvars32.bat" goto missing 
if not exist "%DXSDK_DIR%Include\d3d9.h" goto missingdxsdk
@"%VS110COMNTOOLS%\vsvars32.bat"

:missing
@echo Microsoft Visual Studio 2012 not detected
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