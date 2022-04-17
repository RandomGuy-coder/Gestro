#ifndef GESTRO_CAPTUREANDDETECT_H
#define GESTRO_CAPTUREANDDETECT_H

#include "opencv2/opencv.hpp"
#include "SkinColorDetector.h"
#include "FingerCounter.h"
#include "FingerAndCoordinates.h"
#include "Capture.h"
#include "CallbackInterface.h"
#include "DetectInterface.h"

using namespace std;
using namespace cv;

enum Resolution{
    WIDTH_1280 = 1280,
    HEIGHT_720 = 720,
    WIDTH_1920 = 1920,
    HEIGHT_1080 = 1080
};

class CaptureAndDetect: public DetectInterface {
public:
    CaptureAndDetect();
    void init(CallbackInterface*, Resolution width = WIDTH_1280, Resolution height=HEIGHT_720);
    void calibrateValues(int, int, int, int);
    void calibrateColorPressed();
    void displayImage(String image);
    bool calibrate = false;
    void calibrateBackgroundRemover();
    void newFrame(Mat) override;

private:
    Mat currentFrame;
    String toDisplay = "unprocessed";
    FingerAndCoordinates fingerAndCoordinates;
    SkinColorDetector skinDetector;
    FingerCounter fingerCounter;
    bool backgroundCalibrated = false;
    Ptr<BackgroundSubtractor> backgroundRemover;
    Rect roi;
    CallbackInterface *callback;
    Capture capture;

};
#endif //GESTRO_CAPTUREANDDETECT_H
