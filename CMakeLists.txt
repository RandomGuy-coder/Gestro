set(CMAKE_CXX_STANDARD 11)
cmake_minimum_required(VERSION 3.21)
project(Gestro VERSION "1.0")

add_definitions(-DPROJECT_NAME="${CMAKE_PROJECT_NAME}")
add_definitions(-DPROJECT_VERSION="${CMAKE_PROJECT_VERSION}")

add_executable(Gestro ${PROJECT_SOURCE_DIR}/src/main.cpp)
set_target_properties(Gestro PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(src/gui)
add_subdirectory(src/gesture_detection)
add_subdirectory(src/ubuntu_controls)
target_link_libraries(Gestro gui)
## UNIT TESTING ###

enable_testing()

#find_package(Boost COMPONENTS unit_test_framework REQUIRED)
add_subdirectory(libraries/googletest_src)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
file(GLOB TEST_SRCS ${PROJECT_SOURCE_DIR}/tests/*.cpp)

foreach(testSrc ${TEST_SRCS})
    # Get extension-less file name
    get_filename_component(testName ${testSrc} NAME_WE)
    # Add target
    add_executable(${testName} ${testSrc})
    # Link to Boost, source code and other external libraries
    target_link_libraries(${testName} gtest gtest_main gesture_detection)
    # Put test executables in their own directory
    set_target_properties(${testName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/test/bin)

    # Add test to execution
    add_test(
            NAME ${testName}
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test/bin
            COMMAND ${testName}
    )
endforeach(testSrc)

