@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy catlimb%1.in catlimb.in >nul

catlimb

fc catlimb%1.ans catlimb.out
pause
del catlimb.in
del catlimb.out
goto end


:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end