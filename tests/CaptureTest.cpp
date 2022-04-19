#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE FingerCounterTest
#include <boost/test/unit_test.hpp>
#include "FingerCounter.h"
#include "FingerAndCoordinates.h"

using namespace std;
using namespace cv;

BOOST_AUTO_TEST_CASE(constructor){
    FingerCounter fingerCounter;

    BOOST_CHECK(&fingerCounter);
}

BOOST_AUTO_TEST_CASE(no_finger_est){
    FingerCounter fingerCounter;
    Mat img = imread("../../tests/testImage.jpg", CV_8UC1);
    FingerAndCoordinates coor = fingerCounter.findFingersCount(img, img);
    BOOST_CHECK(coor.command == NO_FINGER);
}

BOOST_AUTO_TEST_CASE(finger_test){
    FingerCounter fingerCounter;
    Mat img = imread("../../tests/sampleImage3.jpg", IMREAD_GRAYSCALE);
    int num;
    for(int i = 0; i < 16; i++) {
        FingerAndCoordinates coor = fingerCounter.findFingersCount(img, img);
        num = coor.command;
    }
}

