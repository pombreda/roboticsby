if not exist "C:\WINDOWS\Microsoft.NET\Framework\v3.5\Csc.exe" goto missingdotnetframework
@"%VS90COMNTOOLS%\vsvars32.bat"

:missingdotnetframework
@echo Microsoft .Net Framewok 3.5 not detected
@pause
@echo on
@exit
goto :eof