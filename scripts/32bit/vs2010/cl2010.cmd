if not exist "%VS100COMNTOOLS%\vsvars32.bat" goto missing 
if not exist "%DXSDK_DIR%Include\d3d9.h" goto missingdxsdk
@"%VS100COMNTOOLS%\vsvars32.bat"

:missing
@echo Microsoft Visual Studio 2010 not detected
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