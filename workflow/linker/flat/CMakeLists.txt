cmake_minimum_required(VERSION 4.2.0)

project("workflow_linker_flat")

# set source files
set(SOURCES
    custom_lib.c
    custom_lib.h
    main.c
)

# add library
add_library(custom_lib 
    STATIC custom_lib.c)

# tell main.c where custom_lib.h is
target_include_directories(custom_lib 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add the entrypoint
add_executable(workflow_linker_flat main.c)

# ensure main.c can use custom lib function
target_link_libraries(workflow_linker_flat PRIVATE custom_lib)

    