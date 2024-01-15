file(GLOB SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

if (BUILD_SHARED_LIBS)
    add_library(test_message SHARED ${SOURCE_FILE})
    target_compile_definitions(test_message PUBLIC -DMESSAGE_LIB_SHARED_BUILD)
    target_compile_definitions(test_message PRIVATE -DMESSAGE_LIB_EXPORTS)
else()
    add_library(test_message STATIC ${SOURCE_FILE})
endif()

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

set_target_properties(test_message PROPERTIES
    DEBUG_POSTFIX "_debug"
    RELEASE_POSTFIX "_release"
)

install(TARGETS test_message
        EXPORT message_export_target
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib"
        ARCHIVE DESTINATION "lib"
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION "include"
        FILES_MATCHING PATTERN "*.h"
)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION "include"
        FILES_MATCHING PATTERN "*.hpp"
)

install(EXPORT message_export_target
        FILE message_lib.cmake
        DESTINATION lib/cmake/test_message
)


include(CMakePackageConfigHelpers)
# generate the config file that is includes the exports
configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/message_config.cmake.in
    "${CMAKE_SOURCE_DIR}/cmake/message_config.cmake"
    INSTALL_DESTINATION "lib/cmake/test_message"
)

# generate the version file for the config file
write_basic_package_version_file(
    "${CMAKE_SOURCE_DIR}/cmake/message_config_version.cmake"
    VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_SOURCE_DIR}/cmake/message_config.cmake
    ${CMAKE_SOURCE_DIR}/cmake/message_config_version.cmake
    DESTINATION lib/cmake/test_message
)

export(EXPORT message_export_target FILE ${CMAKE_SOURCE_DIR}/cmake/message_config_version.cmake)