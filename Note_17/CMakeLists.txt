cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(test_zmq LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH /opt/zmq)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_package(ZeroMQ REQUIRED)

add_executable(hw_server zmq_server.cpp)

target_include_directories(hw_server
  PRIVATE ${ZeroMQ_INCLUDE_DIRS}
)

target_link_libraries(hw_server
  PRIVATE ${ZeroMQ_LIBRARIES}
)

add_executable(hw_client zmq_client.cpp)

target_include_directories(hw_client
  PRIVATE ${ZeroMQ_INCLUDE_DIRS}
)

target_link_libraries(hw_client
  PRIVATE ${ZeroMQ_LIBRARIES}
)
