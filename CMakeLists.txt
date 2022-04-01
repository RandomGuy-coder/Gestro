cmake_minimum_required(VERSION 3.21)
project(Ubuntu_GestureControl)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(OpenCV 4.5 REQUIRED PATHS "/usr/local/")
find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(Ubuntu_GestureControl
        main.cpp src/gui/widget.cpp src/gui/widget.h src/gui/controller_dialog.h src/gui/controller_dialog.cpp src/gui/control_gui.pro src/gui/controller_dialog.ui)

target_link_libraries(Ubuntu_GestureControl ${OpenCV_LIBS})

target_link_libraries(Ubuntu_GestureControl Qt5::Widgets)