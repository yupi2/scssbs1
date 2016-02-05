@echo off

set "FILES_TO_BUILD=dllmain.cpp"

set "WARNINGS=-Wall -Wextra -pedantic"

set "CCCCCCCCC=C:\msys64\mingw32\bin\g++"

@echo on
%CCCCCCCCC% -O2 -std=c++14 %WARNINGS% -s -shared -m32 -o scssbs1.dll %FILES_TO_BUILD%
@echo off

:end
pause
