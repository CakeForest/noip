@echo off
if "%1" == "" goto Loop
@echo Testing Data %1
copy lamp%1.in lamp.in
copy lamp%1.out lamp.ans
time < enter
lamp
time < enter
check
type result.dat
del lamp.in
del lamp.ans
del lamp.out
del result.dat
pause
goto End
:Loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:End
