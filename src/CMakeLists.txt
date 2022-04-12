set(CMAKE_CXX_STANDARD 11)

cmake_minimum_required(VERSION 3.21)
project(Gestro VERSION 1.0.0)

add_subdirectory(gui)
add_subdirectory(gesture_detection)
add_subdirectory(ubuntu_controls)

add_executable(Gestro
        main.cpp)

target_link_libraries(Gestro gui)
target_link_libraries(Gestro ubuntu_controls)

#message(STATUS "DIR=${PROJECT_SOURCE_DIR}")