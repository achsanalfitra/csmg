@echo off
setlocal

set CIVETWEB_IMPL_DIR=path\to\civetweb\src
set CIVETWEB_INCL_DIR=path\to\civetweb\include
set OPENSSL_INCL_DIR=path\to\openssl\root\include
set OPENSSL_LIB_DIR=path\to\openssl\lib

:: when you install from shininglight productions, its in OpenSSL-Win64\lib\VC\x64\M**, this workflow was built using the MT

cd build

:: run cmake version: export compile commands
cmake -G "Ninja" ^
      -D CMAKE_EXPORT_COMPILE_COMMANDS=ON ^
      -D CIVETWEB_IMPL_DIR="%CIVETWEB_IMPL_DIR%" ^
      -D CIVETWEB_INCL_DIR="%CIVETWEB_INCL_DIR%" ^
      -D OPENSSL_INCL_DIR="%OPENSSL_INCL_DIR%" ^
      -D OPENSSL_LIB_DIR="%OPENSSL_LIB_DIR%" ^
      ..

endlocal