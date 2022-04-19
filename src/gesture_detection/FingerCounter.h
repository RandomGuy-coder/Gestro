#ifndef GESTRO_FINGERCOUNTER_H
#define GESTRO_FINGERCOUNTER_H
#include "FingerAndCoordinates.h"
#include "opencv2/opencv.hpp"
#include "vector"
#include "Iir.h"
#include "CaptureAndDetectCallbackInterface.h"
#include "Commands.h"

using namespace cv;
using namespace std;

class FingerCounter {
public:
    FingerCounter(void);
    FingerAndCoordinates findFingersCount(Mat input_image, Mat frame);
    void ConnectCallback(CaptureAndDetectCallbackInterface*);

private:
    Scalar color_blue;
    Scalar color_green;
    Scalar color_white;
    Scalar color_yellow;
    CaptureAndDetectCallbackInterface* palmCallback;
    double findPointsDistance(Point a, Point b);
    double findAngle(Point a, Point b, Point c);
    vector<int> fingers;
    int currentFinger = 0;
    int oldFinger = 0;
    Point oldFarPoint;
    Point farthest_point(vector<Vec4i> defects, vector<Point> contour, Point centroid);
    Iir::Butterworth::LowPass<2> xFilter;
    Iir::Butterworth::LowPass<2> yFilter;
    int getFinger();
    Point getHighestPoint(const Mat &frame, const vector<vector<Point>> &contours, int biggest_contour_index,
                        vector<Vec4i> &defects);
};

#endif //GESTRO_FINGERCOUNTER_H
