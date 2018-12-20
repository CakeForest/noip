@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy cowtract%1.in cowtract.in >nul

cowtract

fc cowtract%1.out cowtract.out
pause
del cowtract.in
del cowtract.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end