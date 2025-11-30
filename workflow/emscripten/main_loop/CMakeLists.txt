cmake_minimum_required(VERSION 4.2.0)

set(project_name ems_main_loop)

project(${project_name} C)

set(SOURCES
    main.c
)

add_executable(${project_name} ${SOURCES})

target_include_directories(
    ${project_name}
    PUBLIC
    ${EMSCRIPTEN_INCLUDE_DIR}
)