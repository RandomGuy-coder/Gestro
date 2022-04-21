#include <gtest/gtest.h>
#include "FingerCounter.h"
using namespace GestureDetection;

TEST(FingerCounterTest, constructor) {
    FingerCounter fingerCounter;
    Mat img = imread("../../tests/testImage.jpg", CV_8UC1);
    FingerAndCoordinates coor = fingerCounter.findFingersCount(img, img);
    EXPECT_EQ(coor.command, NO_FINGER);
}

TEST(FingerCounterTest, NoFinger15Rep) {
    FingerCounter fingerCounter;
    Mat img = imread("../../tests/testing.jpg", IMREAD_GRAYSCALE);

    for (int i = 0; i < 15; i++){
        FingerAndCoordinates coor = fingerCounter.findFingersCount(img, img);
        EXPECT_EQ(coor.command, NO_FINGER);
    }
}