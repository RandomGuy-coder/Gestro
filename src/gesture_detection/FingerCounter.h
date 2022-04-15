#ifndef GESTRO_FINGERCOUNTER_H
#define GESTRO_FINGERCOUNTER_H
#include "FingerAndCoordinates.h"
#include "opencv2/imgproc.hpp"
#include "vector"

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
    Scalar color_white;
    Scalar color_yellow;

    double findPointsDistance(Point a, Point b);
    double findAngle(Point a, Point b, Point c);
    vector<int> fingers;
    bool fingerChanged = false;
    int currentFinger = 0;
    int oldFinger = 0;
    Point oldFarPoint;
    Point farthest_point(vector<Vec4i> defects, vector<Point> contour, Point centroid);

    int getFinger();

    Point
    getHighestPoint(const Mat &frame, const vector<vector<Point>> &contours, int biggest_contour_index,
                    vector<Vec4i> &defects);
};

#endif //GESTRO_FINGERCOUNTER_H
