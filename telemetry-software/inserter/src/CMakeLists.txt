
cmake_minimum_required(VERSION 3.17)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

project(eclipse-telemetry VERSION 1.0)

#
#   Import InfluxDB-cxx project targets
#

set(INFLUXDB_IMPORTS "" CACHE FILEPATH "Path to cmake script to import Influxdb-cxx CMake targets.")

if(NOT INFLUXDB_IMPORTS)
    message(FATAL_ERROR "Please provide the path to import Influxdb-cxx targets.")
endif()

include(${INFLUXDB_IMPORTS})

# CURL is required
find_package(CURL REQUIRED MODULE)

#
# Listing source files
# Important: Add new source folder to this list
#

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_executable(eclipse-telemetry ${SOURCES})

# Use C++17
target_compile_features(eclipse-telemetry PUBLIC cxx_std_17)

#
# Include directories
#
target_include_directories(eclipse-telemetry
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

#
# Linking with dependencies
#
target_link_libraries(eclipse-telemetry
    PRIVATE InfluxData::InfluxDB
    PRIVATE CURL::libcurl)

#
# Install
#
install(TARGETS eclipse-telemetry
    DESTINATION bin)
