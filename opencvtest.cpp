//
// Created by tushar on 02/02/2022.
//
#include "opencv2/opencv.hpp"
#include "iostream"
#include "stdio.h"
#include "SkinColorDetector.h"
#include "FaceRemover.h"
#include "BackgroundRemover.h"
#include "FingerCounter.h"

using namespace cv;
using namespace std;

SkinColorDetector skinDetector;
int lowThres = 50, highThres = 10, dilation_size = 5;

void on_trackbar(int, void*) {
    skinDetector.calibrateTrackBar(lowThres, highThres, dilation_size);
}

int main(int, char**)
{
    VideoCapture cap(0);

    if (!cap.isOpened())
    {
        cerr << "Cannot open the video camera" << endl;
        return -1;
    }
    cap.set(3, 1280);
    cap.set(4, 720);

    cout << cap.get(CAP_PROP_FOURCC) << endl;

//    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
//    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);
//    double fps = cap.get(CAP_PROP_FPS);
//
//    cout << "The resolution of the video is: " << dWidth << " x " << dHeight << endl;
//    cout << "Frame rate is: " << fps << endl;

//    SkinColorDetector skinDetector;
    Mat frame, frameOutput, foreground, skinMask, fingerCounterDebug;

    int maximum = 256;
    // create window for trackbars
    namedWindow("trackbars", 0);
    // create memory to store trackbar name on window
    char TrackBarName[50];
    sprintf(TrackBarName, "lowThres");
    sprintf(TrackBarName, "highThres");
    sprintf(TrackBarName, "dilation_size");
    // create trackbars and insert them into windows
    createTrackbar("lowThres", "trackbars", &lowThres, maximum, on_trackbar);
    createTrackbar("highThres", "trackbars", &highThres, maximum, on_trackbar);
    createTrackbar("dilation_size", "trackbars", &dilation_size, 49, on_trackbar);

    FaceRemover faceRemover;
    BackgroundRemover backgroundRemover;
    FingerCounter fingerCounter;

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
        putText(frameOutput, "Please position one hand to cover", Point(670, 40), FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2, LINE_AA);
        putText(frameOutput, "both rectangles and press the 's' key", Point(670, 80), FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2, LINE_AA);

        foreground = backgroundRemover.getForeground(frame);
        faceRemover.removeFaces(frame, foreground);
        skinMask = skinDetector.getSkinMask(foreground);
        fingerCounterDebug = fingerCounter.findFingersCount(skinMask, frameOutput);

//        imshow(window_name, frame);
        if (!backgroundRemover.getCalibrated()) {
            backgroundRemover.calibrate(frame);
        }
        if (!skinDetector.getCalibrated()) {
            imshow("Detect Skin Color", frameOutput);
        } else {
            imshow("Binarised Hand Only", skinMask);
            imshow("Finger Detection", fingerCounterDebug);
            if (counter == 30) {
                cout << (fingerCounter.getFingerNumber()) << endl;
                counter = 0;
            }

            counter += 1;
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

    return 0;
}

