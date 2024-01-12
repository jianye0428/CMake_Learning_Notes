
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hello-world LANGUAGES CXX)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

file(GLOB HEADER ${CMAKE_SOURCE_DIR}/include/*.h)
file(GLOB SOURCE ${CMAKE_SOURCE_DIR}/src/*.cpp)

add_executable(
    ${PROJECT_NAME}
    ${HEADER}
    ${SOURCE}
    ${CMAKE_SOURCE_DIR}/hello_world.cpp
)