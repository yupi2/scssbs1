@echo off

del scssbs1.dll

set "BUILDFILES=dllmain.cpp"

set "pre=source-sdk-2013/mp/src"

set "INCLUDES=-I%pre%/ -I%pre%/public/ -I%pre%/public/tier0/ -I%pre%/game/"
set "INCLUDES=%INCLUDES% -I%pre%/public/tier1/ -I%pre%/common/ -I%pre%/game/client/"
set "INCLUDES=%INCLUDES% -I%pre%/game/server/ -I%pre%/game/shared/"

set "WARNINGS=-Wall -Wextra -pedantic -Wno-unknown-pragmas"

set "stuff=C:\msys64\mingw32\bin"
set "PATH=%PATH%;%stuff%"

set "OPTIONS=-O2 -std=c++14 -s -shared -m32 -DGNUC -DRAD_TELEMETRY_DISABLED"

@echo on
g++ %WARNINGS% %OPTIONS% -o scssbs1.dll %INCLUDES% %BUILDFILES%
@echo off

:end
pause
