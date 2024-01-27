cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(link_python LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(PythonInterp REQUIRED)

find_package(PythonLibs ${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR} EXACT REQUIRED)
# find_package(Python COMPONENTS Interpreter Development REQUIRED)

add_executable(hello_embedded_python hello_embedded_python.c)


# -DPYTHON_INCLUDE_DIRS=/usr/include/python2.7
target_include_directories(hello_embedded_python
  PRIVATE ${PYTHON_INCLUDE_DIRS}
)
# -DPYTHON_LIBRARIES=/usr/lib
target_link_libraries(hello_embedded_python
  PRIVATE ${PYTHON_LIBRARIES}
)
