@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy ship%1.in ship.in >nul

ship

fc ship%1.out ship.out
pause
del ship.in
del ship.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end