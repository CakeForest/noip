:loop
make
a
b
fc out1.txt out2.txt
pause

if errorlevel 1 goto end
goto loop
:end