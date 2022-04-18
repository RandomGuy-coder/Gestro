#ifndef GESTRO_CONTROLLERSCREENCALLBACKINTERFACE_H
#define GESTRO_CONTROLLERSCREENCALLBACKINTERFACE_H
#include "opencv2/opencv.hpp"
#include "FingerAndCoordinates.h"

class ControllerScreenCallbackInterface {
public:
    virtual void updateImage(cv::Mat) = 0;
    virtual void updateCalibratedTrackbar(int, int, int, int) = 0;
    virtual void fingerDetected(FingerAndCoordinates) = 0;
};
#endif //GESTRO_CONTROLLERSCREENCALLBACKINTERFACE_H
