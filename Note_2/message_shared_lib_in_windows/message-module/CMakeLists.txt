include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

file(GLOB HEADER ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_library(test_message SHARED ${SOURCE})

# 添加别名，以便库可以在构建树中使用，例如在测试时
add_library(test_message::test_message ALIAS test_message)

target_include_directories(test_message
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>/include
    $<INSTALL_INTERFACE:include>
)

set_target_properties(test_message PROPERTIES 
    CXX_STANDARD 11
    CMAKE_CXX_STANDARD_REQUIRED True
)

install(TARGETS test_message
        EXPORT message_export_target
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib"
        ARCHIVE DESTINATION "lib")

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ 
        DESTINATION "include"
        FILES_MATCHING PATTERN "*.h")
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ 
        DESTINATION "include"
        FILES_MATCHING PATTERN "*.hpp")