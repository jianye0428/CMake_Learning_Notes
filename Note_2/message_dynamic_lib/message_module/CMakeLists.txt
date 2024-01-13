include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# 将指定的源码编译到库中 第一个参数是目标名字，生成的库的实际名称将由CMake通过在前面添加前缀lib和适当的扩展名作为后缀来形成
# 第二个参数指定静态库或者动态库, 此处的静态库
add_library(
    test_message
    SHARED
    ${HEADER}
    ${SOURCE}
)