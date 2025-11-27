cmake_minimum_required(VERSION 4.2.0)

set(project_name civet_web_embedding)

project(${project_name} C)

set(SOURCES
    main.c
)

add_executable(
    ${project_name} ${SOURCES}
)

target_link_libraries(
    ${project_name}
    PRIVATE
    ${CIVET_WEB_LIB_DIR}/libcivetweb.a
    ${OPENSSL_LIB_DIR}/libssl.lib
    ${OPENSSL_LIB_DIR}/libcrypto.lib
    ws2_32 # for when using a windows machine
)

target_compile_definitions(
    ${project_name} 
    PRIVATE
    USE_IPV6
    USE_WEBSOCKET
    OPENSSL_API_3_0
)


target_include_directories(
    ${project_name}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CIVETWEB_INCL_DIR}
    ${CIVETWEB_IMPL_DIR}
    ${OPENSSL_INCL_DIR}
)
