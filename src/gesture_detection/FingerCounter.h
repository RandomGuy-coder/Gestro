#ifndef GESTRO_FINGERCOUNTER_H
#define GESTRO_FINGERCOUNTER_H
#include "FingerAndCoordinates.h"
#include "opencv2/imgproc.hpp"

using namespace cv;
using namespace std;

class FingerCounter {
public:
    FingerCounter(void);
    FingerAndCoordinates findFingersCount(Mat input_image, Mat frame);
//    int getFingerNumber() {return fingerNumber;}

private:
    Scalar color_blue;
    Scalar color_green;
    Scalar color_red;
    Scalar color_black;
    Scalar color_white;
    Scalar color_yellow;
    Scalar color_purple;
    double findPointsDistance(Point a, Point b);
    double findAngle(Point a, Point b, Point c);

    int fingerNumber = 0;

    Point farthest_point(vector<Vec4i> defects, vector<Point> contour, Point centroid);
};

#endif //GESTRO_FINGERCOUNTER_H
