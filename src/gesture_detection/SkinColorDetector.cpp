#include "SkinColorDetector.h"

using namespace cv;
using namespace std;

/**
 * It initializes the class variables to default values.
 */
SkinColorDetector::SkinColorDetector(void) {
    hUpper = 0;
    hLower = 0;
    sUpper = 0;
    sLower = 0;
    vUpper = 0;
    vLower = 0;
    offsetHighThreshold = 50;
    offsetLowThreshold = 10;
    calibrated = false;

    dilation_size = 5;

    skinColorSamplerRect1, skinColorSamplerRect2;
}

/**
 * It draws two rectangles on the input frame, one at the center and one at the top
 *
 * @param inputFrame The frame that is being processed.
 */
void SkinColorDetector::drawSkinColorSampler(Mat inputFrame) {
    int frameWidth = inputFrame.size().width, frameHeight = inputFrame.size().height;
    int rectSize = 100;
    Scalar rectColor = (0, 0, 255);

    skinColorSamplerRect1 =  Rect(frameWidth / 5, frameHeight / 2, rectSize, rectSize);
    skinColorSamplerRect2 =  Rect(frameWidth / 5, frameHeight / 3, rectSize, rectSize);

    rectangle(inputFrame, skinColorSamplerRect1, rectColor);
    rectangle(inputFrame, skinColorSamplerRect2, rectColor);
}

/**
 * It takes a frame as input, converts it to HSV, samples two regions of the frame, and calculates the thresholds for the
 * skin color detector
 *
 * @param inputFrame The frame to be used for calibration.
 *
 * @return The lower and upper bounds for the hue and saturation values.
 */
vector<int> SkinColorDetector::calibrate(Mat inputFrame) {
    Mat inputFramehsv;
    cvtColor(inputFrame, inputFramehsv, COLOR_BGR2HSV);

    Mat sample1 = Mat(inputFramehsv, skinColorSamplerRect1);
    Mat sample2 = Mat(inputFramehsv, skinColorSamplerRect2);

    calculateThresholds(sample1, sample2);
    calibrated = true;
    return {hLower, hUpper, sLower, sUpper};
}

/**
 * It calculates the upper and lower thresholds for the HSV values of the skin color
 *
 * @param sample1 The first sample of skin color.
 * @param sample2 The second sample of skin color.
 */
void SkinColorDetector::calculateThresholds(Mat sample1, Mat sample2) {

    Scalar hsvMeansSample1 = mean(sample1);
    Scalar hsvMeansSample2 = mean(sample2);

    MeansSample1 = hsvMeansSample1;
    MeansSample2 = hsvMeansSample2;

    hUpper = max(hsvMeansSample1[0], hsvMeansSample2[0]);
    hLower = 1;

    sUpper = max(hsvMeansSample1[1], hsvMeansSample2[1]);
    sLower = min(hsvMeansSample1[1], hsvMeansSample2[1]);

    vUpper = 255;
    vLower = 0;
}

/**
 * This function takes in the HSV values of the skin color and sets the upper and lower bounds of the HSV values
 *
 * @param H_MIN The minimum value of the Hue channel.
 * @param H_MAX The maximum value of the Hue channel.
 * @param S_MIN Minimum value for the Saturation channel
 * @param S_MAX The maximum value of the saturation channel.
 */
void SkinColorDetector::calibrateValues(int H_MIN, int H_MAX, int S_MIN, int S_MAX) {

    hUpper = H_MAX;
    hLower = H_MIN;

    sUpper = S_MAX;
    sLower = S_MIN;

}

/**
 * It takes an input frame, converts it to HSV, then uses the inRange function to create a mask of the skin color
 *
 * @param inputFrame The input frame from the camera
 *
 * @return A binary image of the skin mask.
 */
Mat SkinColorDetector::getSkinMask(Mat inputFrame) {

    Mat skinMask;
    Mat frame;
    Mat inputFramehsv;
    cvtColor(inputFrame, inputFramehsv, COLOR_BGR2HSV);

    inRange(inputFramehsv,Scalar(1, sLower, vLower), Scalar(hUpper, sUpper, vUpper), skinMask);
    inRange(inputFramehsv, Scalar(50, sLower, vLower), Scalar(150, sUpper, vUpper), frame);
    skinMask = skinMask - frame;

    Mat sE = getStructuringElement(MORPH_ELLIPSE, {3,3});
    morphologyEx(skinMask, skinMask, MORPH_OPEN, sE);

    cv::dilate(skinMask, skinMask, cv::Mat(), Point(-1,-1),2);

    return skinMask;
}

/**
 * It takes a binary image and performs an opening operation on it
 *
 * @param binaryInput The input image in binary format.
 * @param seShape The shape of the structuring element.
 * @param seSize The size of the structuring element.
 */
void SkinColorDetector::opening(Mat binaryInput, int seShape, Point seSize) {
    Mat sE = getStructuringElement(seShape, seSize);
    morphologyEx(binaryInput, binaryInput, MORPH_OPEN, sE);
}