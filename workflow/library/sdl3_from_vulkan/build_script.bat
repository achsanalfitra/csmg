@echo off
setlocal

set BUILD_DIR=build
set VULKAN_INCLUDE_DIR=C:\VulkanSDK\1.4.328.1\Include
set VULKAN_LIB_DIR=C:\VulkanSDK\1.4.328.1\Lib
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
      -D VULKAN_INCLUDE_DIR="%VULKAN_INCLUDE_DIR%" ^
      -D VULKAN_LIB_DIR="%VULKAN_LIB_DIR%" ^
      ..

endlocal