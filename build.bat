@echo off

set "BUILDFILES=dllmain.cpp"

set "INCLUDES=-I."

set "WARNINGS=-Wall -Wextra -pedantic"

set "stuff=C:\msys64\mingw32\bin"
set "PATH=%PATH%;%stuff%"

set "OPTIONS=-O2 -std=c++14 -s -shared -m32"

@echo on
g++ %WARNINGS% %OPTIONS% -o scssbs1.dll %INCLUDES% %BUILDFILES%
@echo off

:end
pause
