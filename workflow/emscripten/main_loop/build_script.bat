@echo off
setlocal

set EMSCRIPTEN_INCLUDE_DIR=path\to\emsdk\upstream\emscripten\cache\sysroot\include

:: when you install from shininglight productions, its in OpenSSL-Win64\lib\VC\x64\M**, this workflow was built using the MT

cd build

:: run cmake version: export compile commands
cmake -G "Ninja" ^
      -D CMAKE_EXPORT_COMPILE_COMMANDS=ON ^
      -D EMSCRIPTEN_INCLUDE_DIR="%EMSCRIPTEN_INCLUDE_DIR%" ^
      ..

endlocal