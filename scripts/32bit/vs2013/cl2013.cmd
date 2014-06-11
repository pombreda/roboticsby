if not exist "%VS120COMNTOOLS%\vsvars32.bat" goto missingvisualstudio
if not exist "%DXSDK_DIR%Include\d3d9.h" goto missingdxsdk
@"%VS120COMNTOOLS%\vsvars32.bat"

:missingvisualstudio
@echo Microsoft Visual Studio 2013 not detected
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