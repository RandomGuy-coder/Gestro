//
// Created by tushar on 03/04/2022.
//

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
    CaptureAndDetect(void);
    void calibrateValues(int, void*);
    static void on_trackbar(int, void*);
    void start(function<void(Mat)> callTo);
    void stop();
    const string trackbarWindowName = "TrackBars";

private:
    int H_MIN;
    int H_MAX;
    int S_MIN;
    int S_MAX;
    int V_MIN;
    int V_MAX;
    thread uthread;
    SkinColorDetector skinDetector;
    void createTrackBars();
    void captureAndTrack();
    function<void(Mat)> callback;


};
#endif //GESTRO_CAPTUREANDDETECT_H
