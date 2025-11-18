@echo off
setlocal

set BUILD_DIR=build
:: set LIBRARY_DIR=\{path_to_csmg}\csmg\workflow\linker\independent\library
:: library dir must be full path. Fill {path_to_smg} with your own path to the root project

:: create build dir
if exist %BUILD_DIR% rd /s /q %BUILD_DIR%
mkdir %BUILD_DIR%
cd %BUILD_DIR%

:: run cmake version: simple
:: cmake -D LIBARY_DIR="%LIBARY_DIR%" ^
::       ..
    
:: run cmake version: export compile commands
cmake -G "Ninja" ^
      -D CMAKE_EXPORT_COMPILE_COMMANDS=ON ^
      -D LIBRARY_DIR="%LIBRARY_DIR%" ^
      ..

endlocal