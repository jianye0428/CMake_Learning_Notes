cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hello-world LANGUAGES CXX)

# 设置可执行文件到bin文件夹下
set(EXECUTE_FILE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_FILE})

# 设置动态库到lib文件夹下
set(LIB_FILE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${LIB_FILE})

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/output/)
endif()

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/message-module
)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/hello_world.cpp
) 

target_link_libraries(
    ${PROJECT_NAME}
    test_message   
)