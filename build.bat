@echo off

set "FILES_TO_BUILD=dllmain.cpp hack.cpp util.cpp log.cpp"

set "mingw32bin=C:\msys64\mingw32\bin"
set "mingw32inc=C:\msys64\mingw32\i686-w64-mingw32\include C:\msys64\mingw32\include"

set "PATH=%PATH%;%mingw32bin%;"

set "CLANG_DISABLED_WARNINGS=-Wno-newline-eof -Wno-reserved-id-macro -Wno-padded -Wno-missing-prototype-for-cc -Wno-c99-extensions -Wno-missing-prototypes"
set "CLANG_WARNINGS=-Weverything -Wextra -pedantic -fcolor-diagnostics %CLANG_DISABLED_WARNINGS%"

@echo on
clang++ -O2 -std=c++14 %CLANG_WARNINGS% -shared -m32 -I "%mingw32inc%" -o scssbs1.dll %FILES_TO_BUILD%
@echo off

:end
pause
