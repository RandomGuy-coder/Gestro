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
    int offsetLowThreshold;
    int offsetHighThreshold;
    Scalar MeansSample1, MeansSample2;
    int dilation_size;

    bool calibrated;

    Rect skinColorSamplerRect1, skinColorSamplerRect2;

    void calculateThresholds(Mat sample1, Mat sample2);
    void opening(Mat binaryInput, int seShape, Point seSize);
    void setValues();

public:
    SkinColorDetector(void);

    void drawSkinColorSampler(Mat inputFrame);
    void calibrate(Mat inputFrame);
    Mat getSkinMask(Mat inputFrame);
    bool getCalibrated() {return calibrated;}
    void calibrateValues(int H_MIN, int H_MAX, int S_MIN, int S_MAX, int V_MIN, int V_MAX);
};


#endif //UBUNTU_GESTURECONTROL_SKINCOLORDETECTOR_H
