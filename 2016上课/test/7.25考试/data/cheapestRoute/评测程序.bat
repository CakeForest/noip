@echo off
if "%1"=="" goto loop
echo TEST
echo Test%1
copy cheapestRoute%1.in cheapestRoute.in >nul

cheapestRoute

fc cheapestRoute%1.out cheapestRoute.out
pause
del cheapestRoute.in
del cheapestRoute.out
goto end
:loop
  for %%i in (1 2 3 4 5 6 7 8 9 10 11) do call %0 %%i
:end