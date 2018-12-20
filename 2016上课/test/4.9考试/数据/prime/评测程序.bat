@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy prime%1.in prime.in >nul

prime

fc prime%1.out prime.out
pause
del prime.in
del prime.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end