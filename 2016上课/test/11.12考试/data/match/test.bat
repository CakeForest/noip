@echo off
    set str=match
	for /L %%i in (0,1,9) do (
	%str%_gen %%i > %str%%%i.in
	%str% < %str%%%i.in >%str%%%i.out )
    pause