# set minimum cmake version
cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
# project name and language
project(test_catch2 LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# example library
add_library(sum_integers sum_integers.cpp)
# main code
add_executable(sum_up main.cpp)
target_link_libraries(sum_up sum_integers)

# testing binary
add_executable(cpp_test test.cpp)
target_link_libraries(cpp_test sum_integers)

enable_testing()
add_test(
  NAME catch_test
  COMMAND $<TARGET_FILE:cpp_test> --success
)