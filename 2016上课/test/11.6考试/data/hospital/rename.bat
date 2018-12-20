@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy guards.out%1  guards%1.out  >nul

del guards.out%1

pause


goto end
:loop
  for %%i in (1	2	3	4	5	6	7	8	9	10 ) do call %0 %%i
:end