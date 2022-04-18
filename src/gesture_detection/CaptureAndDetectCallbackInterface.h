//
// Created by tushar on 17/04/22.
//

#ifndef GESTRO_CAPTUREANDDETECTINTERFACE_H
#define GESTRO_CAPTUREANDDETECTINTERFACE_H

using namespace cv;

class CaptureAndDetectCallbackInterface{
public:
    virtual void newFrame(Mat) = 0;
    virtual bool checkForPalm() = 0;
};

#endif //GESTRO_CAPTUREANDDETECTINTERFACE_H
