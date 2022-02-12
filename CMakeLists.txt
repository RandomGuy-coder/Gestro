cmake_minimum_required(VERSION 3.21)
project(Ubuntu_GestureControl)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV 4.5 REQUIRED PATHS "/usr/local/")

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(Ubuntu_GestureControl
        opencvtest.cpp)
target_link_libraries(Ubuntu_GestureControl ${OpenCV_LIBS})

message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")