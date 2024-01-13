cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(hello-world LANGUAGES CXX)

# 设置可执行文件到bin文件夹下
set(EXECUTE_FILE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTE_FILE})

set(TEST_MESSAGE ${CMAKE_SOURCE_DIR}/third-party/lib/test_message.lib)

include_directories(
    ${CMAKE_SOURCE_DIR}/third-party/include
)

add_executable(
    ${PROJECT_NAME}
    ${CMAKE_SOURCE_DIR}/hello_world.cpp
) 

target_link_libraries(
    ${PROJECT_NAME} 
    ${TEST_MESSAGE} 
)

if (MSVC)
  file(GLOB MODEL "${CMAKE_SOURCE_DIR}/third-party/bin/*.dll")
  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${MODEL}
                     $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()