cmake_minimum_required(VERSION 4.2.0)

project("workflow_interop_c_cpp")

# set source files
set(SOURCES
    custom_lib.cpp
    custom_lib.h
    main.c
)

# add library
add_library(custom_lib 
    STATIC custom_lib.cpp)

# tell main.c where custom_lib.h is
target_include_directories(custom_lib 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add the entrypoint
add_executable(workflow_interop_c_cpp main.c)

# ensure main.c can use custom lib function
target_link_libraries(workflow_interop_c_cpp PRIVATE custom_lib)

    