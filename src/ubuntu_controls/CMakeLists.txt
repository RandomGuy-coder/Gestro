find_package(ALSA REQUIRED)
find_package(X11 REQUIRED)

set(GCC_COVERAGE_COMPILE_FLAGS "-lasound")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_library(ubuntu_controls
        KeyboardEvent.cpp KeyboardAction.cpp KeyboardAction.h MouseControl.cpp MouseControl.h MouseAction.cpp MouseAction.h WindowControl.cpp WindowControl.h WindowAction.cpp WindowAction.h VolumeControl.cpp VolumeControl.h)

if(ALSA_FOUND)
    include_directories(${ALSA_INCLUDE_DIRS})
    target_link_libraries(ubuntu_controls ${ALSA_LIBRARIES})
endif(ALSA_FOUND)

include_directories(${X11_INCLUDE_DIRS})
target_link_libraries(ubuntu_controls "-lX11" )

