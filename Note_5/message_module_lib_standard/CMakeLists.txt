cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hello-world LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_SHARED_LIBS "Specifies the type of libraries (SHARED or STATIC) to build" OFF)

# Set install direcotory
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/output/)
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

message(STATUS "Build type:                                       ${CMAKE_BUILD_TYPE}")
message(STATUS "C flags, Debug configuration:                     ${CMAKE_C_FLAGS_DEBUG}")
message(STATUS "C flags, Release configuration:                   ${CMAKE_C_FLAGS_RELEASE}")
message(STATUS "C flags, Release configuration with Debug info:   ${CMAKE_C_FLAGS_RELWITHDEBINFO}")
message(STATUS "C flags, minimal Release configuration:           ${CMAKE_C_FLAGS_MINSIZEREL}")
message(STATUS "C++ flags, Debug configuration:                   ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "C++ flags, Release configuration:                 ${CMAKE_CXX_FLAGS_RELEASE}")
message(STATUS "C++ flags, Release configuration with Debug info: ${CMAKE_CXX_FLAGS_RELWITHDEBINFO}")
message(STATUS "C++ flags, minimal Release configuration:         ${CMAKE_CXX_FLAGS_MINSIZEREL}")

add_subdirectory(${CMAKE_SOURCE_DIR}/message_module)

include_directories(
    ${CMAKE_SOURCE_DIR}/message_module/include
)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/hello_world.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    test_message
)