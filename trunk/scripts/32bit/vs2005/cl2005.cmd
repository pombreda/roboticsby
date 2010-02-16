if not exist "%VS80COMNTOOLS%\vsvars32.bat" goto missing 
@"%VS80COMNTOOLS%\vsvars32.bat"

:missing
@echo Microsoft Visual Studio 2005 not detected
@pause
@echo on
@exit
goto :eof