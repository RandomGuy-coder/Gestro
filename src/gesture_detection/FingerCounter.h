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

/**
 * @brief checks the number of fingers and sends the respective command to be processed.
 *
 * This class is called from the CaptureAndDetect after the initial image processing is done,
 * the fingers and stored in the buffer. Once the buffer size is 15 the finger that occurs
 * the most number of times in the buffer is considered and the appropriate command is sent.
 * If finger is one or 3 then the coordinates are sent until a new finger is detected.
 */
class FingerCounter {
public:
    /**
    * The constructor for the FingerCounter class. Initializes the colors and iir filters.
    */
    FingerCounter(void);

    /**
    * It finds the contours of the hand, finds the convex hull and the defects, and then counts the number of fingers
    *
    * @param input_image The image that we want to find the fingers in.
    * @param frame The frame from the camera
    *
    * @return a struct of type FingerAndCoordinates.
    */
    FingerAndCoordinates findFingersCount(Mat input_image, Mat frame);

    /**
    * This function is used to connect the callback interface of CaptureAndDetect with this class
    *
    * @param callback The callback function that will be called when the fist is detected.
    */
    void ConnectCallback(CaptureAndDetectCallbackInterface*);

private:
    /** @brief scalar to store blue color */
    Scalar color_blue;
    /** @brief scalar to store green color */
    Scalar color_green;
    /** @brief scalar to store white color */
    Scalar color_white;
    /** @brief scalar to store yellow color */
    Scalar color_yellow;
    /** @brief Callback interface to detect fist */
    CaptureAndDetectCallbackInterface* palmCallback;
    /** @brief to store number of fingers in the buffer for 15 frames */
    vector<int> fingers;
    /** @brief store the current detected finger*/
    int currentFinger = 0;
    /** @brief last detected finger */
    int oldFinger = 0;
    /** @brief last detected far point */
    Point oldFarPoint;

    /** @brief 2nd order low pass iir filter to process x coordinates */
    Iir::Butterworth::LowPass<2> xFilter;
    /** @brief 2nd order low pass iir filter to process y coordinates */
    Iir::Butterworth::LowPass<2> yFilter;

    /**
    * It counts the number of times each finger is detected and returns the finger that is detected the most
    *
    * @return The finger that is most frequently detected.
    */
    int getFinger();

    /**
    * It finds the highest point of the hand
    *
    * @param frame The frame to draw on
    * @param contours The contours of the hand
    * @param biggest_contour_index The index of the biggest contour in the vector of contours.
    * @param defects The convexity defects of the hand.
    *
    * @return The highest point of the hand.
    */
    Point getHighestPoint(const Mat &frame, const vector<vector<Point>> &contours, int biggest_contour_index,
                        vector<Vec4i> &defects);

    /**
    * It returns the point on the contour that is the farthest from the centroid
    *
    * @param defects the convexity defects of the hand
    * @param contour the contour of the hand
    * @param centroid The centroid of the hand
    *
    * @return the point with the highest y value.
    */
    Point farthest_point(vector<Vec4i> defects, vector<Point> contour, Point centroid);

    /**
    * It finds the distance between two points
    *
    * @param a The first point
    * @param b The second point.
    *
    * @return The distance between two points.
    */
    double findPointsDistance(Point a, Point b);

    /**
    * It finds the angle between the three points
    *
    * @param a point one
    * @param b point two
    * @param c point three
    *
    * @return The angle between the three points.
    */
    double findAngle(Point a, Point b, Point c);
};

#endif //GESTRO_FINGERCOUNTER_H
