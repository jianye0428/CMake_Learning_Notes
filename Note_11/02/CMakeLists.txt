cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hello_os LANGUAGES CXX)

add_executable(${PROJECT_NAME} hello_os.cpp)

# 通过target_compile_definitions()命令向目标（hello_os）添加预定义宏IS_LINUX、IS_MACOS或者IS_WINDOWS，该宏在编译过程中将生效。
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  target_compile_definitions(${PROJECT_NAME} PUBLIC "IS_LINUX")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  target_compile_definitions(${PROJECT_NAME} PUBLIC "IS_MACOS")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
  target_compile_definitions(${PROJECT_NAME} PUBLIC "IS_WINDOWS")
endif()