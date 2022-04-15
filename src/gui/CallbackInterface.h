#ifndef TEST_CALLBACKINTERFACE_H
#define TEST_CALLBACKINTERFACE_H
#include "opencv2/opencv.hpp"
#include "FingerAndCoordinates.h"

class CallbackInterface {
public:
    virtual void updateImage(cv::Mat) = 0;
    virtual void updateCalibratedTrackbar(int, int, int, int) = 0;
    virtual void fingerDetected(FingerAndCoordinates) = 0;
};
#endif //TEST_CALLBACKINTERFACE_H
