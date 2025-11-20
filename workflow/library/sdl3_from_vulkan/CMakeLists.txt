cmake_minimum_required(VERSION 4.2.0)

set(PROJECT_NAME workflow_link_library_sdl3_from_vulkan)

project(PROJECT_NAME)

# set source files
set(SOURCES
    main.cpp
)

add_executable(PROJECT_NAME ${SOURCES})

target_include_directories(PROJECT_NAME 
    PRIVATE
    ${VULKAN_INCLUDE_DIR}
    ${VULKAN_LIB_DIR}
)

target_link_libraries(PROJECT_NAME PRIVATE 
     ${VULKAN_LIB_DIR}/SDL3.lib
     ${VULKAN_LIB_DIR}/vulkan-1.lib
)

    