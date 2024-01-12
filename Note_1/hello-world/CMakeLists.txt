cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hello-world LANGUAGES CXX)
# ${PROJECT_NAME} ==> 输出可执行文件的名字
add_executable(${PROJECT_NAME} hello_world.cpp)