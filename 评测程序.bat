@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy matrix%1.in matrix.in >nul

matrix

fc matrix%1.out matrix.out
pause
del matrix.in
del matrix.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end