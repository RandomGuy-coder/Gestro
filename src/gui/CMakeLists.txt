set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_library(gui StartScreen.cpp StartScreen.h widget.ui ControllerScreen.h ControllerScreen.cpp controller_dialog.ui)
target_include_directories(gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gui gesture_detection)
target_link_libraries(gui Qt5::Widgets)