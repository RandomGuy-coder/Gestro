#include <gtest/gtest.h>
#include "SkinColorDetector.h"
using namespace GestureDetection;

TEST(SkinColorDetector, constructor) {
    SkinColorDetector skinColorDetector;
    EXPECT_EQ(skinColorDetector.getCalibrated(), false);
}

TEST(SkinColorDetector, calibrateColourCheck) {
    SkinColorDetector skinColorDetector;
    Mat img = imread("../../tests/hand_color.jpg", IMREAD_ANYCOLOR);
    skinColorDetector.drawSkinColorSampler(img);
    vector<int> values =  skinColorDetector.calibrate(img);
    EXPECT_EQ(skinColorDetector.getCalibrated(), true);
    EXPECT_EQ(values[0], 1);
    EXPECT_EQ(values[1], 15);
}