//
// Created by tushar on 02/02/2022.
//
#include "opencv2/opencv.hpp"
#include "iostream"
#include "stdio.h"
#include "SkinColorDetector.h"
#include "FaceRemover.h"
#include "BackgroundRemover.h"

using namespace cv;
using namespace std;

SkinColorDetector skinDetector;
int lowThres = 50, highThres = 10;

void on_trackbar(int, void*) {
    skinDetector.calibrateTrackBar(lowThres, highThres);
}

//void createHSVTrackbars() {
//    // create window for trackbars
//    namedWindow("trackbars", 0);
//    // create memory to store trackbar name on window
//    char TrackBarName[50];
//    sprintf(TrackBarName, "H_MIN", H_MIN);
//    sprintf(TrackBarName, "H_MAX", H_MAX);
//    sprintf(TrackBarName, "S_MIN", S_MIN);
//    sprintf(TrackBarName, "S_MAX", S_MAX);
//    sprintf(TrackBarName, "V_MIN", V_MIN);
//    sprintf(TrackBarName, "V_MAX", V_MAX);
//    // create trackabrs and insert them into windows
//    createTrackbar("H_MIN", "trackbars", &H_MIN, H_MAX, skinDetector.calibrateTrackBar);
//    createTrackbar("H_MAX", "trackbars", &H_MAX, H_MAX, skinDetector.calibrateTrackBar);
//    createTrackbar("S_MIN", "trackbars", &S_MIN, S_MAX, skinDetector.calibrateTrackBar);
//    createTrackbar("S_MAX", "trackbars", &S_MAX, S_MAX, skinDetector.calibrateTrackBar);
//    createTrackbar("V_MIN", "trackbars", &V_MIN, V_MAX, skinDetector.calibrateTrackBar);
//    createTrackbar("V_MAX", "trackbars", &V_MAX, V_MAX, skinDetector.calibrateTrackBar);
//}

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

    string window_name = "My Camera Feed";
    namedWindow(window_name); //create a window called "My Camera Feed"

//    SkinColorDetector skinDetector;
    Mat frame, HSVframe, frameOutput, foreground, skinMask;
    // int H_MIN = 0, H_MAX = 256, S_MIN = 0, S_MAX = 256, V_MIN = 0, V_MAX = 256;
//     int lowThres = 50, highThres = 10,
    int maximum = 256;
    // create window for trackbars
    namedWindow("trackbars", 0);
    // create memory to store trackbar name on window
    char TrackBarName[50];
//    sprintf(TrackBarName, "H_MIN", H_MIN);
//    sprintf(TrackBarName, "H_MAX", H_MAX);
//    sprintf(TrackBarName, "S_MIN", S_MIN);
//    sprintf(TrackBarName, "S_MAX", S_MAX);
//    sprintf(TrackBarName, "V_MIN", V_MIN);
//    sprintf(TrackBarName, "V_MAX", V_MAX);
    sprintf(TrackBarName, "lowThres");
    sprintf(TrackBarName, "highThres");
    // create trackbars and insert them into windows
//    createTrackbar("H_MIN", "trackbars", &H_MIN, H_MAX, skinDetector.calibrateTrackBar());
//    createTrackbar("H_MAX", "trackbars", &H_MAX, H_MAX, skinDetector.calibrateTrackBar());
//    createTrackbar("S_MIN", "trackbars", &S_MIN, S_MAX, skinDetector.calibrateTrackBar());
//    createTrackbar("S_MAX", "trackbars", &S_MAX, S_MAX, skinDetector.calibrateTrackBar());
//    createTrackbar("V_MIN", "trackbars", &V_MIN, V_MAX, skinDetector.calibrateTrackBar());
//    createTrackbar("V_MAX", "trackbars", &V_MAX, V_MAX, skinDetector.calibrateTrackBar());
    createTrackbar("lowThres", "trackbars", &lowThres, maximum, on_trackbar);
    createTrackbar("highThres", "trackbars", &highThres, maximum, on_trackbar);

    FaceRemover faceRemover;
    BackgroundRemover backgroundRemover;

      while (true)
    {
        bool bSuccess = cap.read(frame); // read a new frame from video

        //Breaking the while loop if the frames cannot be captured
        if (bSuccess == false)
        {
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
        }

        //show the frame in the created window
//        cvtColor(frame, HSVframe, COLOR_BGR2HSV);
//        imshow(window_name, frame);
        frameOutput = frame.clone();
        skinDetector.drawSkinColorSampler(frameOutput);
        foreground = backgroundRemover.getForeground(frame);
//        foreground = frame.clone();
        faceRemover.removeFaces(frame, foreground);
        skinMask = skinDetector.getSkinMask(foreground);
        if (skinDetector.getCalibrated()) {
            imshow(window_name, skinMask);
        } else {
            imshow("frameO", frameOutput);
        }



        //wait for for 10 ms until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop
        //If any key is not pressed withing 10 ms, continue the loop
        int pressedKey = waitKey(10);
        if (pressedKey == 27) { // esc
            cout << "Esc key is pressed by user. Stopping the video" << endl;
            break;
        } else if (pressedKey == 98) { // b
                backgroundRemover.calibrate(frame);
        } else if (pressedKey == 115) { // s
            skinDetector.calibrate(frame);
            destroyWindow("frameO");
        }
    }

    return 0;
}

