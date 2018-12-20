@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy match%1.in match.in >nul

match

fc match%1.out match.out
pause
del match.in
del match.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end