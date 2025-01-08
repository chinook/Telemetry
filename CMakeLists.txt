
cmake_minimum_required(VERSION 2.8)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

project(eclipse_telemetry)

SET(FLAGS "-std=c++17 -Wall")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS}")

#
# Listing source files
# Important: Add new source folder to this list
#

file(GLOB SOURCES "source/*.cpp")

#
# Include directories
#

include_directories(/usr/local/Cellar/influxdb-cxx/0.4.0/include/)
include_directories(/usr/local/Cellar/curl/7.71.1/include/)
include_directories(/usr/local/Include/)
include_directories(/usr/local/Cellar/openssl@1.1/1.1.1g/include/)

#
# Library directories
#

# Windows
#if (WIN32)
    # TODO
#endif (WIN32)

# Unix
if (UNIX)
   link_directories(${EXECUTABLE_OUTPUT_PATH}/libs/unix/)
endif (UNIX)
link_directories(/usr/local/Cellar/openssl@1.1/1.1.1g/lib/)
link_directories(/usr/local/Cellar/cpprestsdk/2.10.16/lib/)

add_executable(eclipse_telemetry ${SOURCES})

#
# Linking with dependencies
#

target_link_libraries(eclipse_telemetry InfluxDB)
target_link_libraries(eclipse_telemetry curl)
target_link_libraries(eclipse_telemetry ssl)
target_link_libraries(eclipse_telemetry crypto)
target_link_libraries(eclipse_telemetry cpprest)
