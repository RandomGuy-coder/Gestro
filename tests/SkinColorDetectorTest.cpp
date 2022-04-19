#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SkinColorDetectorTest
#include <boost/test/unit_test.hpp>
#include "SkinColorDetector.h"

using namespace std;
using namespace cv;

BOOST_AUTO_TEST_CASE(calibrationCheck){
    SkinColorDetector skinDetector;

    BOOST_CHECK(&skinDetector);
    Mat img = imread("../../tests/testImage.jpg");
    vector<int> values = skinDetector.calibrate(img);
    BOOST_CHECK(!values.empty());
    BOOST_CHECK(skinDetector.getCalibrated());
}

BOOST_AUTO_TEST_CASE(calibrateManually){
    SkinColorDetector skinDetector;
    BOOST_CHECK(&skinDetector);
    Mat img = imread("../../tests/testImage.jpg");
    Mat imgToVerify = imread("../../tests/test.jpg");
    skinDetector.drawSkinColorSampler(img);
    BOOST_CHECK(norm(img, imgToVerify, NORM_L1));
}




