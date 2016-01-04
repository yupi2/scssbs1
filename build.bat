@echo off

set "FILES_TO_BUILD=dllmain.cpp"

set "mingw32bin=C:\msys64\mingw32\bin"
set "PATH=%PATH%;%mingw32bin%;"

set "WARNINGS=-Wall -Wextra -pedantic"

@echo on
g++ -O2 -std=c++14 %WARNINGS% -s -shared -m32 -o scssbs1.dll %FILES_TO_BUILD%
@echo off

:end
pause
