//
// Created by terrancewong on 12/02/2022.
//

#include "SkinColorDetector.h"
#include "opencv2/opencv.hpp"

using namespace cv;

SkinColorDetector::SkinColorDetector(void) {
    hUpper = 0;
    hLower = 0;
    sUpper = 0;
    sLower = 0;
    vUpper = 0;
    vLower = 0;

    calibrated = false;

    dilation_size = 5;

    skinColorSamplerRect1, skinColorSamplerRect2;
}

void SkinColorDetector::drawSkinColorSampler(Mat inputFrame) {
    int frameWidth = inputFrame.size().width, frameHeight = inputFrame.size().height;
    int rectSize = 200;
    Scalar rectColor = (0, 0, 255);

    skinColorSamplerRect1 =  Rect(frameWidth / 5, frameHeight / 2, rectSize, rectSize);
    skinColorSamplerRect2 =  Rect(frameWidth / 5, frameHeight / 3, rectSize, rectSize);

    rectangle(inputFrame, skinColorSamplerRect1, rectColor);
    rectangle(inputFrame, skinColorSamplerRect2, rectColor);
}

void SkinColorDetector::calibrate(Mat inputFrame) {
    Mat inputFramehsv;
    cvtColor(inputFrame, inputFramehsv, COLOR_BGR2HSV);

    Mat sample1 = Mat(inputFramehsv, skinColorSamplerRect1);
    Mat sample2 = Mat(inputFramehsv, skinColorSamplerRect2);

    calculateThresholds(sample1, sample2);
    calibrated = true;
}

void SkinColorDetector::calculateThresholds(Mat sample1, Mat sample2) {
    int offsetLowThreshold = 50, offsetHighThreshold = 10;
    Scalar hsvMeansSample1 = mean(sample1), hsvMeansSample2 = mean(sample2);
    MeansSample1 = hsvMeansSample1;
    MeansSample2 = hsvMeansSample2;

    hUpper = max(hsvMeansSample1[0], hsvMeansSample2[0]) + offsetHighThreshold;
    hLower = min(hsvMeansSample1[0], hsvMeansSample2[0]) - offsetLowThreshold;

    sUpper = max(hsvMeansSample1[1], hsvMeansSample2[1]) + offsetHighThreshold;
    sLower = min(hsvMeansSample1[1], hsvMeansSample2[1]) - offsetLowThreshold;

    // V channel shouldn't be used, but this will cause some kind of bug if we ignored it
    vUpper = max(hsvMeansSample1[2], hsvMeansSample2[2]) + offsetHighThreshold;
    vLower = min(hsvMeansSample1[2], hsvMeansSample2[2]) - offsetLowThreshold;
    //vUpper = 255;
    //vLower = 0;
}

void SkinColorDetector::calibrateTrackBar(int offsetLow, int offsetHigh, int dilation_size2) {
    dilation_size = dilation_size2;
    int offsetLowThreshold = offsetLow, offsetHighThreshold = offsetHigh;
    Scalar hsvMeansSample1 = MeansSample1, hsvMeansSample2 = MeansSample2;

    hUpper = max(hsvMeansSample1[0], hsvMeansSample2[0]) + offsetHighThreshold;
    hLower = min(hsvMeansSample1[0], hsvMeansSample2[0]) - offsetLowThreshold;

    sUpper = max(hsvMeansSample1[1], hsvMeansSample2[1]) + offsetHighThreshold;
    sLower = min(hsvMeansSample1[1], hsvMeansSample2[1]) - offsetLowThreshold;

    // V channel shouldn't be used, but this will cause some kind of bug if we ignored it
    vUpper = max(hsvMeansSample1[2], hsvMeansSample2[2]) + offsetHighThreshold;
    vLower = min(hsvMeansSample1[2], hsvMeansSample2[2]) - offsetLowThreshold;
    //vUpper = 255;
    //vLower = 0;
}

Mat SkinColorDetector::getSkinMask(Mat inputFrame) {
    Mat skinMask;

    if (!calibrated) {
        skinMask = Mat::zeros(inputFrame.size(), CV_8UC1);
        return skinMask;
    }

    Mat inputFramehsv;
    cvtColor(inputFrame, inputFramehsv, COLOR_BGR2HSV);

    inRange(inputFramehsv,Scalar(hLower, sLower, vLower), Scalar(hUpper, sUpper, vUpper), skinMask);
    opening(skinMask, MORPH_ELLIPSE, {5, 5});
//    opening(skinMask, MORPH_ELLIPSE, {dilation_size, dilation_size});
//    dilate(skinMask, skinMask, Mat(), Point(-1, -1), 3);
    dilate(skinMask, skinMask, getStructuringElement(MORPH_ELLIPSE, Size( 11, 11 )),Point(-1, -1), 3);

    return skinMask;
}

void SkinColorDetector::opening(Mat binaryInput, int seShape, Point seSize) {
    Mat sE = getStructuringElement(seShape, seSize);
    morphologyEx(binaryInput, binaryInput, MORPH_OPEN, sE);
}