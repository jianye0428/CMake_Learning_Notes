
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hello-world LANGUAGES CXX)

# 设置可执行文件到bin文件夹下
set(EXECUTE_FILE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_FILE}) # 运行时输出文件夹 一般指build文件夹

set(TEST_MESSAGE ${CMAKE_SOURCE_DIR}/third_party/lib/libtest_message.so)

include_directories(
    ${CMAKE_SOURCE_DIR}/third_party/include
)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/hello_world.cpp
)

#链接  动态库  到  项目  上
# static lib(TEST_MESSAGE) => Project
target_link_libraries(
    ${PROJECT_NAME}
    ${TEST_MESSAGE}
)