cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(python_module LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PythonInterp REQUIRED)
find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)

execute_process(
    COMMAND ${PYTHON_EXECUTABLE} "-c" "import re, numpy; print(re.compile('/__init__.py.*').sub('',numpy.__file__))"
    RESULT_VARIABLE numpy_status # 捕获python脚本执行的状态
    OUTPUT_VARIABLE numpy_location # 捕获修改后的numpy模块文件的位置
    ERROR_QUIET # 抑制进程生成的任何错误
    OUTPUT_STRIP_TRAILING_WHITESPACE #移除输出中的尾随空格
)

if(NOT numpy_status)
    set(NumPy ${numpy_location} CACHE STRING "Location of NumPy")
endif()

execute_process(
    COMMAND ${PYTHON_EXECUTABLE} "-c" "import numpy; print(numpy.__version__)"
    OUTPUT_VARIABLE numpy_version
    ERROR_QUIET
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(NumPy
    FOUND_VAR NumPy_FOUND
    REQUIRED_VARS NumPy
    VERSION_VAR numpy_version
)

add_executable(pure-embedding py3_pure_embedding.cpp)

target_include_directories(pure-embedding
  PRIVATE ${PYTHON_INCLUDE_DIRS}
)

target_link_libraries(pure-embedding
  PRIVATE ${PYTHON_LIBRARIES}
)

add_custom_command(
  OUTPUT
      ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
  COMMAND
      ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
      ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
  DEPENDS
      ${CMAKE_CURRENT_SOURCE_DIR}/use_numpy.py
)

# make sure building pure-embedding triggers the above custom command
target_sources(pure-embedding
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/use_numpy.py
)