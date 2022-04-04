//
// Created by tushar on 03/04/2022.
//
#include "opencv2/opencv.hpp"
#include "SkinColorDetector.h"
#include "FaceRemover.h"
#include "FingerCounter.h"
#include "CaptureAndDetect.h"

#include <utility>

using namespace std;
using namespace cv;

CaptureAndDetect::CaptureAndDetect(void){
    H_MIN = 0; // minimum Hue
    H_MAX = 180; // maximum Hue
    S_MIN = 0; // minimum Saturation
    S_MAX = 255; // maximum Saturation
    V_MIN = 0; // minimum Value
    V_MAX = 255; //maximum Value
}


void CaptureAndDetect::on_trackbar(int value, void* ptr) {
    CaptureAndDetect* file = (CaptureAndDetect*)ptr;
    file->calibrateValues(value, 0);
}

void CaptureAndDetect::calibrateValues(int, void *) {
    if(skinDetector.getCalibrated()) {
        skinDetector.calibrateValues(H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX);
    }
}

void CaptureAndDetect::createTrackBars() {

    namedWindow(trackbarWindowName,0);

    //create memory to store trackbar name on window
    char TrackbarName[50];
    sprintf( TrackbarName, "H_MIN", H_MIN);
    sprintf( TrackbarName, "H_MAX", H_MAX);
    sprintf( TrackbarName, "S_MIN", S_MIN);
    sprintf( TrackbarName, "S_MAX", S_MAX);
    sprintf( TrackbarName, "V_MIN", V_MIN);
    sprintf( TrackbarName, "V_MAX", V_MAX);

    createTrackbar( "H_MIN", trackbarWindowName, &H_MIN, H_MAX, on_trackbar, this);
    createTrackbar( "H_MAX", trackbarWindowName, &H_MAX, H_MAX, on_trackbar, this );
    createTrackbar( "S_MIN", trackbarWindowName, &S_MIN, S_MAX, on_trackbar, this );
    createTrackbar( "S_MAX", trackbarWindowName, &S_MAX, S_MAX, on_trackbar, this );
    createTrackbar( "V_MIN", trackbarWindowName, &V_MIN, V_MAX, on_trackbar, this );
    createTrackbar( "V_MAX", trackbarWindowName, &V_MAX, V_MAX, on_trackbar, this );
}

void CaptureAndDetect::captureAndTrack() {

    VideoCapture cap(0);

    if(!cap.isOpened()){
        cerr<<"cannot open cam" <<endl;
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
        if (!bSuccess || frame.empty())
        {
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
        }

//        //show the flipped frame in the created window
//        flip(frame, frame, 1);
//        frameOutput = frame.clone();
//
//        skinDetector.drawSkinColorSampler(frameOutput);
//
//        if (!skinDetector.getCalibrated()) {
//            imshow("Detect Skin Color", frameOutput);
//        } else {
//            faceRemover.removeFaces(frame);
//
//            //Blur the frame
//            Size kSize;
//            kSize.height = 3;
//            kSize.width = 3;
//            double sigma = 0.3*(3/2 - 1) + 0.8;
//            GaussianBlur(frame,frame,kSize,sigma,0.0,4);
//
//            backgroundRemover ->apply(frame, bgMask);
//
//            copyTo(frame,backgroundRemoved,bgMask);
//            skinMask = skinDetector.getSkinMask(backgroundRemoved);
//            copyTo(frame, newimg, skinMask);
//            fingerCounterDebug = fingerCounter.findFingersCount(skinMask, frame);
//
//
//            imshow("Skin Mask", skinMask);
//
//            imshow("Binarised Hand Only", fingerCounterDebug);
//
            callback(frame);
//            waitKey(1);
//                break;
//            backgroundRemoved = NULL;
//            newimg = NULL;
//            waitKey(10);
//            cout<<"jrtr"<<endl;
        }

        //wait for for 10 ms until any key is pressed.
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop
        //If any key is not pressed withing 10 ms, continue the loop

//        if (pressedKey == 27) { // esc
//            cout << "Esc key is pressed by user. Stopping the video" << endl;
//            break;
//        } else if (pressedKey == 115) { // s
//            skinDetector.calibrate(frame);
//            destroyWindow("Detect Skin Color");
//        }
//    }
}

void CaptureAndDetect::start(function<void(Mat)> callTo) {
    uthread = thread(&CaptureAndDetect::captureAndTrack, this);
    callback = callTo;
}

void CaptureAndDetect::stop() {
    uthread.join();
}
