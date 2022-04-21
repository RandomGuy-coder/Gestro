#ifndef GESTRO_SKINCOLORDETECTOR_H
#define GESTRO_SKINCOLORDETECTOR_H

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

namespace GestureDetection {
/**
 * @brief detects skin colour threshold and creates a skin mask.
 *
 * This class calculates the skin colour from a ROI of the image and
 * then creates a skin mask on request.
 */
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

        /**
         * This method returns the calibrated flag.
         * @return
         */
        bool getCalibrated();

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

        /** @brief These are the upper and lower bounds for the Hue and Saturation values.*/
        int hUpper, hLower, sUpper, sLower, vUpper, vLower;

        /** @brief A variable that stores the mean of the HSV values of the two samples.*/
        Scalar MeansSample1, MeansSample2;

        /** @brief A flag that is set to true when the skin color is calibrated.*/
        bool calibrated;


        /** @brief Creating two rectangles. */
        Rect skinColorSamplerRect1, skinColorSamplerRect2;

        /**
        * It calculates the upper and lower thresholds for the HSV values of the skin color
        *
        * @param sample1 The first sample of skin color.
        * @param sample2 The second sample of skin color.
        */
        void calculateThresholds(Mat sample1, Mat sample2);
    };
}


#endif //GESTRO_SKINCOLORDETECTOR_H
