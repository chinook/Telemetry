
cmake_minimum_required(VERSION 2.8)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

project(eclipse_telemetry)

SET(FLAGS "-std=c++17 -Wall")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}")

#
# Listing source files
# Important: Add new source folder to this list
#

file(GLOB SOURCES "inserter/src/*.cpp")

#
# Include directories
#

include_directories(./inserter/influxdb-cxx/include/)
include_directories(./inserter/influxdb-cxx/src/)
include_directories(./inserter/asio/include/)

#
# Library directories
#

# Windows
#if (WIN32)
    # TODO
#endif (WIN32)

link_directories(/usr/local/lib/)

add_executable(eclipse_telemetry ${SOURCES})

#
# Linking with dependencies
#

target_link_libraries(eclipse_telemetry InfluxDB)
