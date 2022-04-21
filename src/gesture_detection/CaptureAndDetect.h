#ifndef GESTRO_CAPTUREANDDETECT_H
#define GESTRO_CAPTUREANDDETECT_H

#include "opencv2/opencv.hpp"
#include "SkinColorDetector.h"
#include "FingerCounter.h"
#include "FingerAndCoordinates.h"
#include "Capture.h"
#include "ControllerScreenCallbackInterface.h"
#include "CaptureAndDetectCallbackInterface.h"
#include "DisplayControlCallbackInterface.h"
#include "thread"
#include <unistd.h>

using namespace std;
using namespace cv;
using namespace GestureDetection;

/** \brief enum to store resolution */
enum Resolution {
    WIDTH_1280 = 1280,
    HEIGHT_720 = 720,
    WIDTH_1920 = 1920,
    HEIGHT_1080 = 1080
};

/** \brief enum for type of Feed */
enum Feed {
    UNPROCESSED,
    SKINMASK,
    DETECTED
};


namespace Gestro {
/** @brief This class takes care of starting threads to capture image, process and publish commands
 *
 * This class is the mediator between the different functions of the application. Connecting between image
 * capturing, GUI and and DisplayControl to publish the detected commands.
 * */
    class CaptureAndDetect : public CaptureAndDetectCallbackInterface {
    public:

        /**
        * The constructor for the CaptureAndDetect class.
        */
        CaptureAndDetect();

        /**
        * It initializes the capture object, sets the region of interest, sets the callback interface, starts the capture, and
        * starts the thread that processes the frames
        *
        * @param interface The interface that will be called when a gesture is detected.
        * @param width The width of the camera's resolution.
        * @param height The height of the camera's resolution.
        * @param screenWidth The width of the screen in pixels
        * @param screenHeight The height of the screen in pixels.
        */
        void init(ControllerScreenCallbackInterface *, int, int, EnabledCommand *, Resolution width = WIDTH_1280,
                  Resolution height = HEIGHT_720);

        /**
        * It takes in the minimum and maximum values for the hue and saturation channels, and then passes them to the skinDetector
        * object's calibrateValues() function
        *
        * @param hMin Minimum Hue value
        * @param hMax The maximum hue value for the skin color.
        * @param sMin Minimum saturation value for the skin color.
        * @param sMax The maximum saturation value for the skin color.
        */
        void calibrateValues(int, int, int, int);

        /**
        * This function is called by the camera thread when a new frame is available. It sets the recievedFrame variable to the
        * new frame and sets the frameRecieved variable to true.
        *
        * @param incomingFrame The frame that was recieved from the camera.
        */
        void newFrame(Mat) override;

        /**
        * It calls the calibrate function of the skinDetector object, which returns a vector of 4 integers, which are then passed
        * to the callback function updateCalibratedTrackbar, which updates the trackbar values
        */
        void calibrateColorPressed();

        bool calibrate = false;

        /**
        * It creates a background remover object that will be used to remove the background from the video frames
        */
        void calibrateBackgroundRemover();

        /**
        * It sets the value of the variable toDisplay to the value of the parameter feed
        *
        * @param feed The feed to display.
        */
        void displayImage(int);

        /**
        * This function is called by the DisplayControl class to connect the CaptureAndDetect class to the DisplayControl class.
        *
        * @param interface The interface that will be used to communicate with the display control.
        */
        void connectControlCallback(DisplayControlCallbackInterface *);

        /**
        * It takes a frame from the camera, processes it, and sends it to the GUI to be displayed
        */
        void processFrame();

        /**
        * It takes the current frame, and checks to see if there is a palm in it
        *
        * @return A boolean value.
        */
        bool checkForPalm();

        /**
        * It adds a finger to the buffer
        *
        * @param finger The finger that was detected.
        */
        void addToBuffer(FingerAndCoordinates) override;

        /** \brief frame received from capture thread */
        Mat recievedFrame;

    private:
        /** \brief current frame being processed */
        Mat currentFrame;

        /** \brief Fingercoordinate object to store the response */
        FingerAndCoordinates fingerAndCoordinates;

        /** \brief SkinColorDetecter object */
        SkinColorDetector skinDetector;

        /** \brief FingerCounter object */
        FingerCounter fingerCounter;

        /** \brief Bacground substractor object */
        Ptr<BackgroundSubtractor> backgroundRemover;

        /** \brief Region of interest to track the fingers */
        Rect roi;

        /** \brief callback to controller screen GUI */
        ControllerScreenCallbackInterface *callback;

        /** \brief callback to Display Control to send ubuntu commands */
        DisplayControlCallbackInterface *controlInterface;

        /** \brief Cascade classifier to detect fist */
        CascadeClassifier *palmClassifier;

        /** \brief Capture object */
        Capture capture;

        /** \brief thread to start processing images */
        thread uthread;

        /** \brief thread to check for commands and forward to DisplayControl */
        thread commandThread;

        /** \brief buffer to store the finger count, listened by command thread*/
        queue<FingerAndCoordinates> detectedFingers;

        EnabledCommand *commands;

        /** \brief width of the display */
        int displayWidth;

        /** \brief height of the display */
        int displayHeight;

        /** \brief feed to display */
        int toDisplay = UNPROCESSED;

        /** \brief bool to check is background has been calibrated */
        bool backgroundCalibrated = false;

        /** \brief boolean flag to check if recieved new frame from Capture */
        bool frameRecieved = false;

        /**
        * It takes the commands from the queue and executes them
        */
        void processCommands();

    };
}
#endif //GESTRO_CAPTUREANDDETECT_H
