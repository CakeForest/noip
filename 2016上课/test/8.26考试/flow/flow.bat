@echo off
if "%1"=="" goto loop
copy flow%1.in flow.in >nul
echo Problem Test
echo Data %1
time<enter
flow.exe
time<enter
fc flow.out flow%1.out
del flow.in
del flow.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10) do call %0 %%i
:end
