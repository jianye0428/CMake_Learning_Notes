cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hello_world LANGUAGES CXX)

# 设置可执行文件到bin文件夹下
set(EXECUTE_FILE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_FILE})

# 设置动态库到lib文件夹下
set(LIB_FILE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY  ${LIB_FILE})

include_directories(
    ${CMAKE_SOURCE_DIR}/message_module/include
)

# 将message-module添加进来进行编译，这个函数命令将寻找message-module目录下的CMakeLists.txt，如果该目录下没有CMakeLists.txt将报错
# hello_world.cpp要使用message-module模块中编译生成的静态库，所以add_subdirectory命令将message-module添加到项目中, add_subdirectory的顺序必须要先于add_executable命令。
# message-module 为该模块的文件夹名称
add_subdirectory(
    ${CMAKE_SOURCE_DIR}/message_module
)

# add_executable命令将hello_world.cpp编译成可执行文件，其名字为项目名称hello-world，该可执行文件使用target_link_libraries命令将message-module模块下编译生成的静态库test_message链接到可执行文件中
add_executable(
    ${PROJECT_NAME} # 输出的可执行文件名称
    ${CMAKE_SOURCE_DIR}/hello_world.cpp
)
# 链接静态库
target_link_libraries(
    ${PROJECT_NAME}
    test_message
)