@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy age%1.in AGE%1.IN  >nul

del AGE%1.IN

pause


goto end
:loop
  for %%i in (1	2	3	4	5	6	7	8	9	10 ) do call %0 %%i
:end