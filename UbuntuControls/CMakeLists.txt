cmake_minimum_required(VERSION 3.21)
project(Ubuntu_GestureControl)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV 4.5 REQUIRED PATHS "/usr/local/")
find_package(ALSA REQUIRED)
find_package(X11 REQUIRED)

set(GCC_COVERAGE_COMPILE_FLAGS "-lasound")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(Ubuntu_GestureControl
        keyboard_event.cpp keyboardAction.cpp keyboardAction.h mouse_control.cpp mouse_control.h mouseAction.cpp mouseAction.h window_control.cpp window_control.h windowAction.cpp windowAction.h volumeControl.cpp volumeControl.h)
target_link_libraries(Ubuntu_GestureControl ${OpenCV_LIBS})

if(ALSA_FOUND)
    include_directories(${ALSA_INCLUDE_DIRS})
    target_link_libraries(Ubuntu_GestureControl ${ALSA_LIBRARIES})
endif(ALSA_FOUND)

#link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIRS})
target_link_libraries(Ubuntu_GestureControl "-lX11" )

message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")