cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(eigen_tensor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 查找和加载特定的第三方库
#   - CONFIG 参数指示CMake查找Eigen3的CMake配置文件（通常是 Eigen3Config.cmake 或类似名称），其中包含有关库的信息和设置。
#     一旦找到Eigen3库的CMake配置文件，CMake会加载该配置文件并设置相关的变量
find_package(Eigen3 3.4 REQUIRED CONFIG)
# include(CheckCXXCompilerFlag) 是一个用于检查C++编译器标志是否可用的CMake命令
include(CheckCXXCompilerFlag)

check_cxx_compiler_flag("-march=native" _march_native_works)
check_cxx_compiler_flag("-xHost" _xhost_works)

set(_CXX_FLAGS)
if(_march_native_works)
    message(STATUS "Using processor's vector instructions (-march=native compiler flag set)")
    set(_CXX_FLAGS "-march=native")
elseif(_xhost_works)
    message(STATUS "Using processor's vector instructions (-xHost compiler flag set)")
    set(_CXX_FLAGS "-xHost")
else()
    message(STATUS "No suitable compiler flag found for vectorization")
endif()

add_executable(linear-algebra-unoptimized linear_algebra.cpp)
target_link_libraries(linear-algebra-unoptimized
  PRIVATE Eigen3::Eigen
)

add_executable(linear-algebra linear_algebra.cpp)
target_compile_options(linear-algebra
  PRIVATE ${_CXX_FLAGS}
)
target_link_libraries(linear-algebra
  PRIVATE Eigen3::Eigen
)