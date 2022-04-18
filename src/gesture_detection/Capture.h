#ifndef GESTRO_CAPTURE_H
#define GESTRO_CAPTURE_H
#include "opencv2/opencv.hpp"
#include <thread>
#include "DetectInterface.h"

using namespace std;
using namespace cv;

/**
 * A class that captures images from the webcam and calls
 * the callback function with the image.
 */
class Capture {
public:

    /**
     * The constructor for the class.
     */
    Capture();

    /**
    * It initializes the Capture class with the width and height of the image to be captured, and a pointer to the
    * DetectInterface class
    *
    * @param interface The interface that will be called when a new frame is available.
    * @param width The width of the image to be captured.
    * @param height The height of the image to be captured.
    */
    void init(DetectInterface*,int, int);

    /**
    * It starts a thread that runs the imageCap function to read Images
    */
    void start();

    /**
    * It stops the capture thread by setting the running flag to false, and then waits for the thread to finish
    */
    void stop();

private:
    thread uthread;
    bool running = false;
    DetectInterface *callback;
    int height;
    int width;

    /**
    * It captures an image from the webcam, and then calls the callback function with the image
    */
    void imageCap();
};


#endif //GESTRO_CAPTURE_H
