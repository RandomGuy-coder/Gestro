//
// Created by terrancewong on 12/02/2022.
//
#include "opencv2/opencv.hpp"

#ifndef UBUNTU_GESTURECONTROL_SKINCOLORDETECTOR_H
#define UBUNTU_GESTURECONTROL_SKINCOLORDETECTOR_H

using namespace cv;

class SkinColorDetector {
private:
    int hUpper, hLower, sUpper, sLower, vUpper, vLower;
    Scalar MeansSample1, MeansSample2;

    bool calibrated;

    Rect skinColorSamplerRect1, skinColorSamplerRect2;

    void calculateThresholds(Mat sample1, Mat sample2);
    void opening(Mat binaryInput, int seShape, Point seSize);
public:
    SkinColorDetector(void);

    void drawSkinColorSampler(Mat inputFrame);
    void calibrate(Mat inputFrame);
    Mat getSkinMask(Mat inputFrame);
    bool getCalibrated() {return calibrated;}
    void calibrateTrackBar(int offsetLow, int offsetHigh);
};


#endif //UBUNTU_GESTURECONTROL_SKINCOLORDETECTOR_H
