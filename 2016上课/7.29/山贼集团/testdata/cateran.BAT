@echo off
if "%1"=="" goto loop
copy cateran%1.in cateran.in >nul
echo Problem Test
echo Data %1
time<enter
cateran
time<enter
fc cateran.out cateran%1.out
del cateran.in
del cateran.out
pause
goto end
:loop
for %%i in (1 2 3 4 5 6 7 8 9 10)  do call %0 %%i
:end
