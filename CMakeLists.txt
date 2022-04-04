set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.21)
project(TEST)
add_subdirectory(src)

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)
#
#find_package(OpenCV 4.5 REQUIRED PATHS "/usr/local/")
#find_package(Qt5 COMPONENTS Widgets REQUIRED)
#
#include_directories(${OpenCV_INCLUDE_DIRS})
#
#include_directories(${OpenCV_INCLUDE_DIRS})
#add_executable(Ubuntu_GestureControl
#        src/main.cpp)
#
#add_subdirectory(src)
#
#target_link_libraries(Ubuntu_GestureControl ${OpenCV_LIBS})
#
#target_link_libraries(Ubuntu_GestureControl Qt5::Widgets)
#target_link_libraries(Ubuntu_GestureControl gesture_detection)
#target_link_libraries(Ubuntu_GestureControl gui)