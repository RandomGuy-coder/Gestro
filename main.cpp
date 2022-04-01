#include "opencv2/opencv.hpp"
#include "src/gesture_detection/SkinColorDetector.h"
#include "src/gesture_detection/FaceRemover.h"
#include "src/gesture_detection/FingerCounter.h"

using namespace std;
using namespace cv;

int H_MIN = 0; // minimum Hue
int H_MAX = 180; // maximum Hue
int S_MIN = 0; // minimum Saturation
int S_MAX = 255; // maximum Saturation
int V_MIN = 0; // minimum Value
int V_MAX = 255; //maximum Value
const string trackbarWindowName = "TrackBars";
SkinColorDetector skinDetector;


void on_trackbar(int, void*) {
    if(skinDetector.getCalibrated()) {
        skinDetector.calibrateValues(H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX);
    }
}

void createTrackBars() {

    namedWindow(trackbarWindowName,0);

    //create memory to store trackbar name on window
    char TrackbarName[50];
    sprintf( TrackbarName, "H_MIN", H_MIN);
    sprintf( TrackbarName, "H_MAX", H_MAX);
    sprintf( TrackbarName, "S_MIN", S_MIN);
    sprintf( TrackbarName, "S_MAX", S_MAX);
    sprintf( TrackbarName, "V_MIN", V_MIN);
    sprintf( TrackbarName, "V_MAX", V_MAX);

    createTrackbar( "H_MIN", trackbarWindowName, &H_MIN, H_MAX, on_trackbar );
    createTrackbar( "H_MAX", trackbarWindowName, &H_MAX, H_MAX, on_trackbar );
    createTrackbar( "S_MIN", trackbarWindowName, &S_MIN, S_MAX, on_trackbar );
    createTrackbar( "S_MAX", trackbarWindowName, &S_MAX, S_MAX, on_trackbar );
    createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar );
    createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar );
}


int main(int,char**) {

    VideoCapture cap(0);

    if (!cap.isOpened())
    {
        return -1;
    }

    cap.set(3, 1280);
    cap.set(4,720);
    cap.set(6, VideoWriter::fourcc('M','J','P','G'));
    Mat frame, frameOutput, skinMask, bgMask, fingerCounterDebug, backgroundRemoved, newimg;

    // create window for trackbars
    createTrackBars();

    FaceRemover faceRemover;
    FingerCounter fingerCounter;
    Ptr<BackgroundSubtractor> backgroundRemover = createBackgroundSubtractorKNN(200,200.0,false);

    int counter = 0;
    while (true) {

        bool bSuccess = cap.read(frame); // read a new frame from video

        //Breaking the while loop if the frames cannot be captured
        if (bSuccess == false)
        {
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
        }

        //show the flipped frame in the created window
        flip(frame, frame, 1);
        frameOutput = frame.clone();

        skinDetector.drawSkinColorSampler(frameOutput);

        if (!skinDetector.getCalibrated()) {
            imshow("Detect Skin Color", frameOutput);
        } else {
            faceRemover.removeFaces(frame);

            //Blur the frame
            Size kSize;
            kSize.height = 3;
            kSize.width = 3;
            double sigma = 0.3*(3/2 - 1) + 0.8;
            GaussianBlur(frame,frame,kSize,sigma,0.0,4);

            backgroundRemover ->apply(frame, bgMask);
//
            copyTo(frame,backgroundRemoved,bgMask);
            skinMask = skinDetector.getSkinMask(backgroundRemoved);
//            copyTo(frame, newimg, skinMask);
            fingerCounterDebug = fingerCounter.findFingersCount(skinMask, frame);


//            imshow("Skin Mask", skinMask);

            imshow("Binarised Hand Only", fingerCounterDebug);
//            imshow("Fingers", fingerCounterDebug);
            backgroundRemoved = NULL;
            newimg = NULL;
//
        }

        //wait for for 10 ms until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop
        //If any key is not pressed withing 10 ms, continue the loop
        int pressedKey = waitKey(10);
        if (pressedKey == 27) { // esc
            cout << "Esc key is pressed by user. Stopping the video" << endl;
            break;
        } else if (pressedKey == 115) { // s
            skinDetector.calibrate(frame);
            destroyWindow("Detect Skin Color");
        }
    }
}
