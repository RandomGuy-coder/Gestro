#ifndef GESTRO_SKINCOLORDETECTOR_H
#define GESTRO_SKINCOLORDETECTOR_H

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

class SkinColorDetector {
public:
    /**
    * It initializes the class variables to default values.
    */
    SkinColorDetector(void);

    /**
    * It draws two rectangles on the input frame, one at the center and one at the top
    *
    * @param inputFrame The frame that is being processed.
    */
    void drawSkinColorSampler(Mat inputFrame);

    /**
    * It takes a frame as input, converts it to HSV, samples two regions of the frame, and calculates the thresholds for the
    * skin color detector
    *
    * @param inputFrame The frame to be used for calibration.
    *
    * @return The lower and upper bounds for the hue and saturation values.
    */
    vector<int> calibrate(Mat inputFrame);

    /**
    * It takes an input frame, converts it to HSV, then uses the inRange function to create a mask of the skin color
    *
    * @param inputFrame The input frame from the camera
    *
    * @return A binary image of the skin mask.
    */
    Mat getSkinMask(Mat inputFrame);


    bool getCalibrated() {return calibrated;}

    /**
    * This function takes in the HSV values of the skin color and sets the upper and lower bounds of the HSV values
    *
    * @param H_MIN The minimum value of the Hue channel.
    * @param H_MAX The maximum value of the Hue channel.
    * @param S_MIN Minimum value for the Saturation channel
    * @param S_MAX The maximum value of the saturation channel.
    */
    void calibrateValues(int H_MIN, int H_MAX, int S_MIN, int S_MAX);

private:
    int hUpper, hLower, sUpper, sLower, vUpper, vLower;
    Scalar MeansSample1, MeansSample2;
    bool calibrated;
    Rect skinColorSamplerRect1, skinColorSamplerRect2;

    /**
    * It calculates the upper and lower thresholds for the HSV values of the skin color
    *
    * @param sample1 The first sample of skin color.
    * @param sample2 The second sample of skin color.
    */
    void calculateThresholds(Mat sample1, Mat sample2);
};


#endif //GESTRO_SKINCOLORDETECTOR_H
