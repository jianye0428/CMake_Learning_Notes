cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(control-flow LANGUAGES CXX)

set(CXX_STANDARD 11)

# 静态库
add_library(test_lib
  STATIC
  ${CMAKE_SOURCE_DIR}/message.h
  ${CMAKE_SOURCE_DIR}/message.cpp
  ${CMAKE_SOURCE_DIR}/cal_add.h
  ${CMAKE_SOURCE_DIR}/cal_substract.h
  ${CMAKE_SOURCE_DIR}/cal_substract.cpp
)

# 使用-O3编译器优化级别编译库，对目标设置一个私有编译器选项
target_compile_options(test_lib PRIVATE -O3)

# 生成一个源文件列表，以较低的优化选项进行编译
list(APPEND sources_with_lower_optimization
     cal_subtract.cpp
)

# 循环这些源文件，将它们的优化级别调到-O2。使用它们的源文件属性完成
message(STATUS "Setting source properties using IN LISTS syntax:")
foreach(_source IN LISTS sources_with_lower_optimization)
  set_source_files_properties(${_source} PROPERTIES COMPILE_FLAGS -O2)
  message(STATUS "Appending -O2 flag for ${_source}")
endforeach()


# 为了确保设置属性，再次循环并在打印每个源文件的COMPILE_FLAGS属性
message(STATUS "Querying sources properties using plain syntax:")
foreach(_source ${sources_with_lower_optimization})
  get_source_file_property(_flags ${_source} COMPILE_FLAGS)
  message(STATUS "Source ${_source} has the following extra COMPILE_FLAGS: ${_flags}")
endforeach()

add_executable(${PROJECT_NAME} main.cpp) # 将main.cpp 文件编译成可执行文件
target_link_libraries(${PROJECT_NAME} test_lib)
set_source_files_properties(file PROPERTIES property value)