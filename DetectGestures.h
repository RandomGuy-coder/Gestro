//
// Created by tushar on 09/03/2022.
//

#ifndef UBUNTU_GESTURECONTROL_DETECTGESTURES_H
#define UBUNTU_GESTURECONTROL_DETECTGESTURES_H

#include "opencv2/opencv.hpp"
#include "iostream"
#include "stdio.h"
#include "SkinColorDetector.h"
#include "FaceRemover.h"
#include "FingerCounter.h"

using namespace cv;
using namespace std;

class DetectGestures {

    void on_trackbar(int, void*);

private:
    SkinColorDetector skinDetector;
    int H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX;
    const string trackbarWindowName = "TrackBars";
    void createTrackBars();

public:
    DetectGestures(void);
    void startDetection();

};

#endif //UBUNTU_GESTURECONTROL_DETECTGESTURES_H
