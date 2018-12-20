set "name=network"
@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy %name%%1.in %name%.in >nul

%name%

fc %name%%1.out %name%.out
pause
del %name%.in
del %name%.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end