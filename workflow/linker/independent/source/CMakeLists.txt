cmake_minimum_required(VERSION 4.2.0)

project("workflow_linker_independent")

# set source files
set(SOURCES
    ${LIBRARY_DIR}/custom_lib.c
    ${LIBRARY_DIR}/custom_lib.h
    main.c
)

# add library
add_library(custom_lib 
    STATIC ${LIBRARY_DIR}/custom_lib.c)

# tell main.c where custom_lib.h is
target_include_directories(custom_lib 
    PUBLIC ${LIBRARY_DIR})

# add the entrypoint
add_executable(workflow_linker_independent main.c)

# ensure main.c can use custom lib function
target_link_libraries(workflow_linker_independent PRIVATE custom_lib)

    