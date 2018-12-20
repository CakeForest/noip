@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy black%1.in black.in >nul

black

fc black%1.out black.out
pause
del black.in
del black.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end