cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(test_zmq LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH /opt/zmq)

find_package(PkgConfig REQUIRED QUIET)

pkg_search_module(
  ZeroMQ
  REQUIRED libzeromq libzmq lib0mq
  IMPORTED_TARGET
)

if(TARGET PkgConfig::ZeroMQ)
    message(STATUS "Found ZeroMQ")
endif()

add_executable(hw_server zmq_server.cpp)
target_link_libraries(hw_server PkgConfig::ZeroMQ)

add_executable(hw_client zmq_client.cpp)
target_link_libraries(hw_client PkgConfig::ZeroMQ)