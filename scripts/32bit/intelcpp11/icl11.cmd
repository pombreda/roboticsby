if not exist "%ICPP_COMPILER11%\bin\ia32\iclvars_ia32.bat" goto missing 
@"%ICPP_COMPILER11%\bin\ia32\iclvars_ia32.bat"

:missing
@echo Intel C++ 11 not detected
@pause
@echo on
@exit
goto :eof