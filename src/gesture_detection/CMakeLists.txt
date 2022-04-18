add_library(gesture_detection Capture.cpp Capture.h CaptureAndDetectCallbackInterface.h CaptureAndDetect.cpp
        CaptureAndDetect.h FingerCounter.cpp FingerCounter.h SkinColorDetector.cpp SkinColorDetector.h
        FingerAndCoordinates.cpp FingerAndCoordinates.h)

#set(OpenCV_DIR "${CMAKE_CURRENT_BINARY_DIR}/../../../opencv_build")
find_package(OpenCV 4.5 REQUIRED PATHS "/usr/local/")
find_package(Threads)
find_package(iir)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(gesture_detection ${OpenCV_LIBS})
target_link_libraries(gesture_detection ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(gesture_detection PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gesture_detection gui)
target_link_libraries(gesture_detection iir::iir)
