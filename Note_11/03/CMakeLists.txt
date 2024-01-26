cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(arch_dependent LANGUAGES CXX)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/arch_dependent.cpp
)

# 检查空指针类型的大小
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    target_compile_definitions(
        ${PROJECT_NAME}
        PUBLIC "IS_64_BIT_ARCH"
    )
    message(STATUS "Target is 64 bits")
else()
    target_compile_definitions(
        ${PROJECT_NAME}
        PUBLIC "IS_32_BIT_ARCH"
    )
    message(STATUS "Target is 32 bits")
endif()

# 通过定义目标编译定义，让预处理器了解主机处理器架构
if(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i386")
    message(STATUS "i386 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "i686")
    message(STATUS "i686 architecture detected")
elseif(CMAKE_HOST_SYSTEM_PROCESSOR MATCHES "x86_64")
    message(STATUS "x86_64 architecture detected")
else()
    message(STATUS "host processor architecture is unknown")
endif()

target_compile_definitions(
    ${PROJECT_NAME}
    PUBLIC "ARCHITECTURE=${CMAKE_HOST_SYSTEM_PROCESSOR}"
)