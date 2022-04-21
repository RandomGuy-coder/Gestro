#ifndef GESTRO_CAPTURE_H
#define GESTRO_CAPTURE_H
#include "opencv2/opencv.hpp"
#include <thread>
#include "CaptureAndDetectCallbackInterface.h"

using namespace std;
using namespace cv;
using namespace Gestro;

namespace GestureDetection {
/**
 * @brief runs a thread to start camera and capture image
 *
 * A class that captures images from the webcam and calls
 * the callback function with the image.
 */
    class Capture {
    public:

        /** \brief boolean to check if cmaera is running */
        bool running = false;

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
        void init(Gestro::CaptureAndDetectCallbackInterface *, int, int);

        /**
        * It starts a thread that runs the imageCap function to read Images
        */
        void start();

        /**
        * It stops the capture thread by setting the running flag to false, and then waits for the thread to finish
        */
        void stop();

    private:

        /** \brief thread to start image capture */
        thread uthread;

        /** \brief callback to capture and detect */
        Gestro::CaptureAndDetectCallbackInterface *callback;

        /** \brief resolution height */
        int height;

        /** \brief resolution width */
        int width;

        /** \brief captured frame */
        Mat frame;

        /** \brief pointer to VideoCapture */
        VideoCapture *capture;

        /**
        * It captures an image from the webcam, and then calls the callback function with the image
        */
        void imageCap();
    };
}


#endif //GESTRO_CAPTURE_H
