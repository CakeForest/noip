@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy missile%1.in missile.in >nul

missile

fc missile%1.out missile.out
pause
del missile.in
del missile.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end