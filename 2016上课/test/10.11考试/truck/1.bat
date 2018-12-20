@echo off
if "%1"=="" goto loop
echo TEST
echo test%1
copy truck%1.in truck.in >nul

truck
fc truck.out truck%1.ans
pause
del truck.in
del truck.out

goto end
:loop
 for %%i in (1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20) do call %0 %%i
:end