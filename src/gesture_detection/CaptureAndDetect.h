#ifndef GESTRO_CAPTUREANDDETECT_H
#define GESTRO_CAPTUREANDDETECT_H

#include "opencv2/opencv.hpp"
#include "SkinColorDetector.h"
#include "FingerCounter.h"
#include "FingerAndCoordinates.h"
#include "thread"
#include "CallbackInterface.h"

using namespace std;
using namespace cv;

class CaptureAndDetect {
public:
    CaptureAndDetect();
    void calibrateValues(int, int, int, int);
    void start(function<void(Mat)> callTo,  function<void(FingerAndCoordinates)> callToFinger);
    void stop();
    void calibrateColorPressed();
    void displayImage(String image);
    bool calibrate = false;
    void calibrateBackgroundRemover();
    void connectCallback(CallbackInterface*);

private:
    int V_MIN;
    int V_MAX;
    String toDisplay = "unprocessed";
    FingerAndCoordinates fingerAndCoordinates;
    thread uthread;
    SkinColorDetector skinDetector;
    void captureAndTrack();
    function<void(Mat)> callback;
    function<void(FingerAndCoordinates)> fingerCallback;
    bool backgroundCalibrated = false;
    Ptr<BackgroundSubtractor> backgroundRemover;
    Rect roi;
    CallbackInterface *interface;



};
#endif //GESTRO_CAPTUREANDDETECT_H
