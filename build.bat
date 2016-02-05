@echo off

set "BUILDFILES=dllmain.cpp"

set "pre=source-sdk-2013/mp/src"

set "INCLUDES=-I%pre%/public/ -I %pre%/public/tier0/ -I %pre%/public/tier1/"
set "INCLUDES=%INCLUDES% -I %pre%/common"

set "WARNINGS=-Wall -Wextra -pedantic -Wno-unknown-pragmas"

set "stuff=C:\msys64\mingw32\bin"
set "PATH=%PATH%;%stuff%"

set "OPTIONS=-O2 -std=c++14 -s -shared -m32 -DGNUC"

@echo on
g++ %WARNINGS% %OPTIONS% -o scssbs1.dll %INCLUDES% %BUILDFILES%
@echo off

:end
pause
