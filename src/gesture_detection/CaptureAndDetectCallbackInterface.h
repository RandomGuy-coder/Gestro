//
// Created by tushar on 17/04/22.
//

#ifndef GESTRO_CAPTUREANDDETECTINTERFACE_H
#define GESTRO_CAPTUREANDDETECTINTERFACE_H

#include "opencv2/opencv.hpp"
#include "FingerAndCoordinates.h"

using namespace cv;

class CaptureAndDetectCallbackInterface{
public:
    virtual void newFrame(Mat) = 0;
    virtual bool checkForPalm() = 0;
    virtual void addToBuffer(FingerAndCoordinates) = 0;
};

#endif //GESTRO_CAPTUREANDDETECTINTERFACE_H
