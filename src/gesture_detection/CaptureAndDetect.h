#ifndef GESTRO_CAPTUREANDDETECT_H
#define GESTRO_CAPTUREANDDETECT_H

#include "opencv2/opencv.hpp"
#include "SkinColorDetector.h"
#include "FaceRemover.h"
#include "FingerCounter.h"
#include "thread"

using namespace std;
using namespace cv;

class CaptureAndDetect {
public:
    CaptureAndDetect();
    void calibrateValues(int, int, int, int);
    void start(function<void(Mat)> callTo);
    void stop();
    void calibrateColorPressed();
    void displayImage(String image);
    bool calibrate = false;

private:
    int V_MIN;
    int V_MAX;
    String toDisplay;
    thread uthread;
    SkinColorDetector skinDetector;
    void captureAndTrack();
    function<void(Mat)> callback;


};
#endif //GESTRO_CAPTUREANDDETECT_H