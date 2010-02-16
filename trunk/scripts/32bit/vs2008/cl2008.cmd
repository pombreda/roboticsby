if not exist "%VS90COMNTOOLS%\vsvars32.bat" goto missing 
@"%VS90COMNTOOLS%\vsvars32.bat"

:missing
@echo Microsoft Visual Studio 2008 not detected
@pause
@echo on
@exit
goto :eof