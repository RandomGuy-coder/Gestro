#include "FingerCounter.h"

using namespace GestureDetection;

FingerCounter::FingerCounter(void) {
    color_blue = Scalar(255, 0, 0);
    color_green = Scalar(0, 255, 0);
    color_white = Scalar(255, 255, 255);
    color_yellow = Scalar(0, 255, 255);
    xFilter.setup(30,3);
    yFilter.setup(30,3);
}

void FingerCounter::ConnectCallback(CaptureAndDetectCallbackInterface* callback){
        palmCallback = callback;
}

FingerAndCoordinates FingerCounter::findFingersCount(Mat input_image, Mat frame) {
    Mat contours_image = Mat::zeros(input_image.size(), CV_8UC3);

    // check if the source image is good
    if (input_image.empty())
        return {};

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(input_image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // we need at least one contour to work
    if (contours.empty())
        return {};

    // find the biggest contour (let's suppose it's our hand)
    int biggest_contour_index = -1;
    double biggest_area = 0.0;

    for (int i = 0; i < contours.size(); i++) {
        double area = contourArea(contours[i], false);
        if (area > biggest_area) {
            biggest_area = area;
            biggest_contour_index = i;
        }
    }

    if (biggest_contour_index < 0 || biggest_area < 300) {
        oldFinger = 0;
        return {};
    }

    // find the convex hull object for each contour and the defects, two different data structure are needed by the OpenCV api
    vector<Point> hull_points;
    vector<int> hull_ints;

    // for drawing the convex hull and for finding the bounding rectangle
    convexHull(contours[biggest_contour_index], hull_points);
    convexHull(contours[biggest_contour_index],hull_ints,false, true);
    drawContours(frame, contours, biggest_contour_index, color_green, 2 );
    polylines(frame, hull_points, true, color_blue);

    // we need at least 3 points to find the defects
    vector<Vec4i> defects;
    if (hull_ints.size() > 3)
        convexityDefects(contours[biggest_contour_index], hull_ints, defects);
    else
        return {};

    int cnt = 0;

    // we separate the defects keeping only the ones of intrest
    Point start_point;
    Point far_point;
    Point end_point;

    for (int i = 0; i < defects.size(); i++) {
        start_point = contours[biggest_contour_index][defects[i].val[0]];
        end_point = contours[biggest_contour_index][defects[i].val[1]];
        far_point = contours[biggest_contour_index][defects[i].val[2]];
        double angle = findAngle(far_point,start_point,end_point);

        if(defects[i].val[3] > 1000 and angle <=CV_PI/2){
            cnt = cnt+1;
            circle(frame, end_point, 8, color_white, -1);
        }
    }
    if(cnt > 0 and cnt <=5) {
        fingers.push_back(cnt);
    }
    if(fingers.size() == 15) {
        currentFinger = getFinger();
        fingers.clear();
        if (currentFinger != oldFinger) {
            Point farthestPoint = getHighestPoint(frame, contours, biggest_contour_index, defects);
            oldFinger = currentFinger;
            if(currentFinger == 1)
                return {MOUSE_MOVE, xFilter.filter(farthestPoint.x), yFilter.filter(farthestPoint.y)};
        } else if (oldFinger == currentFinger) {
            Point farthestPoint = getHighestPoint(frame, contours, biggest_contour_index, defects);
            farthestPoint.x = xFilter.filter(farthestPoint.x);
            farthestPoint.y = yFilter.filter(farthestPoint.y);
            Point difference = oldFarPoint - farthestPoint;
            oldFarPoint = farthestPoint;
            if(currentFinger == 1) {
                if (sqrt(difference.ddot(difference)) <= 10) {
                    return {MOUSE_CLICK,farthestPoint.x, farthestPoint.y};
                }
            } else if(currentFinger == 2) {
                return {MUTE_UNMUTE};
            } else if(currentFinger ==3) {
                return {MOVE_WINDOW, farthestPoint.x, farthestPoint.y};
            }else if(currentFinger == 4) {
                return{PRESS_SPACE};
            }
        }
    }else if(oldFinger == 1) {
        Point farthestPoint = getHighestPoint(frame, contours, biggest_contour_index, defects);
        return {MOUSE_MOVE, xFilter.filter(farthestPoint.x), yFilter.filter(farthestPoint.y)};
    } else if(oldFinger == 3) {
        Point farthestPoint = getHighestPoint(frame, contours, biggest_contour_index, defects);
        return {MOVE_WINDOW, xFilter.filter(farthestPoint.x), yFilter.filter(farthestPoint.y)};
    }
    return {};
}

Point FingerCounter::getHighestPoint(const Mat &frame, const vector<vector<Point>> &contours, int biggest_contour_index,
                                     vector<Vec4i> &defects) {
    Moments m = moments(contours[biggest_contour_index], true);
    Point center(m.m10/m.m00,m.m01/m.m00);
    Point farthestPoint = farthest_point(defects, contours[biggest_contour_index], center);
    circle(frame, farthestPoint, 8, color_yellow, -1);
    return farthestPoint;
}

int FingerCounter::getFinger() {
    int frequency[6] = {0};
    for(int i : fingers){
        frequency[i]++;
    }
    int max = 0;
    int finger = 0;
    for(int i = 1; i <= 5; i++) {
        if(frequency[i] > max) {
            max = frequency[i];
            finger = i;
        }
    }
    return finger;
}

Point FingerCounter::farthest_point(vector<Vec4i> defects, vector<Point>contour, Point centroid){
    int index = 0;
    int max_y = 0;
    for(int i; i < contour.size(); i++){
        if(contour[i].y > max_y){
            index = i;
        }
    }
    return contour[index];
}

double FingerCounter::findPointsDistance(Point a, Point b) {
    Point difference = a - b;
    return sqrt(difference.ddot(difference));
}

double FingerCounter::findAngle(Point a, Point b, Point c) {
    double ab = findPointsDistance(c, b);
    double bc = findPointsDistance(a, b);
    double ca = findPointsDistance(a, c);
    return acos((bc * bc + ca * ca - ab * ab) / (2 * bc * ca));
}