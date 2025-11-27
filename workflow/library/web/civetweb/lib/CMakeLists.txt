cmake_minimum_required(VERSION 4.2.0)

set(project_name civet_web_library)
project(${project_name} C)

add_library(${project_name} STATIC 
    ${CIVETWEB_IMPL_DIR}/civetweb.c
)

set_target_properties(${project_name} PROPERTIES 
    OUTPUT_NAME "civetweb"
)


# define Feature Flags (Mirrors WITH_IPV6=1, WITH_WEBSOCKET=1, and COPT='-DNO_SSL_DL=1')
target_compile_definitions(${project_name} PRIVATE
    USE_IPV6       
    USE_WEBSOCKET   
    NO_SSL_DL=1     
    OPENSSL_API_3_0
)


target_include_directories(${project_name} 
    PRIVATE ${CIVETWEB_IMPL_DIR}
    ${CIVETWEB_INCL_DIR}
    ${OPENSSL_INCL_DIR}
)

find_package(Threads REQUIRED)

target_link_libraries(${project_name} 
    INTERFACE 
    Threads::Threads 
    ${OPENSSL_LIB_DIR}/libssl.lib
    ${OPENSSL_LIB_DIR}/libcrypto.lib
)