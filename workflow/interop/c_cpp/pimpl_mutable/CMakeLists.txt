cmake_minimum_required(VERSION 4.2.0)

project("workflow_interop_c_cpp_pimpl")

# set source files
set(SOURCES
    shared_object.cpp
    shared_object.h
    main.c
)

# add library
add_library(shared_object 
    STATIC shared_object.cpp)

# tell main.c where custom_lib.h is
target_include_directories(shared_object 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add the entrypoint
add_executable(workflow_interop_c_cpp_pimpl main.c)

# ensure main.c can use custom lib function
target_link_libraries(workflow_interop_c_cpp_pimpl PRIVATE shared_object)

    