#ifndef GESTRO_CAPTUREANDDETECT_H
#define GESTRO_CAPTUREANDDETECT_H

#include "opencv2/opencv.hpp"
#include "SkinColorDetector.h"
#include "FingerCounter.h"
#include "FingerAndCoordinates.h"
#include "Capture.h"
#include "ControllerScreenCallbackInterface.h"
#include "CaptureAndDetectCallbackInterface.h"
#include "DisplayControlCallbackInterface.h"

using namespace std;
using namespace cv;

enum Resolution{
    WIDTH_1280 = 1280,
    HEIGHT_720 = 720,
    WIDTH_1920 = 1920,
    HEIGHT_1080 = 1080
};

enum Feed{
    UNPROCESSED,
    SKINMASK,
    DETECTED
};

class CaptureAndDetect: public CaptureAndDetectCallbackInterface {
public:
    CaptureAndDetect();

    void init(ControllerScreenCallbackInterface*, Resolution width = WIDTH_1280, Resolution height=HEIGHT_720);
    void calibrateValues(int, int, int, int);
    void calibrateColorPressed();
    bool calibrate = false;
    void calibrateBackgroundRemover();
    void newFrame(Mat) override;
    void displayImage(int);
    void connectControlCallback(DisplayControlCallbackInterface*);

private:
    Mat currentFrame;
    int toDisplay = UNPROCESSED;
    FingerAndCoordinates fingerAndCoordinates;
    SkinColorDetector skinDetector;
    FingerCounter fingerCounter;
    bool backgroundCalibrated = false;
    Ptr<BackgroundSubtractor> backgroundRemover;
    Rect roi;
    ControllerScreenCallbackInterface *callback;
    DisplayControlCallbackInterface *controlInterface;
    Capture capture;

};
#endif //GESTRO_CAPTUREANDDETECT_H
