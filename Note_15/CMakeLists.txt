cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(test_openmp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

add_executable(test_openmp test_openmp.cpp)
target_link_libraries(test_openmp
  PUBLIC
      OpenMP::OpenMP_CXX
)

add_executable(test_no_openmp test_no_openmp.cpp)
target_link_libraries(test_no_openmp
  PUBLIC
      OpenMP::OpenMP_CXX
)