#include "CaptureAndDetect.h"

using namespace std;
using namespace cv;

CaptureAndDetect::CaptureAndDetect(void){
}

void CaptureAndDetect::calibrateValues(int hMin, int hMax, int sMin, int sMax) {
    if(skinDetector.getCalibrated()) {
        skinDetector.calibrateValues(hMin, hMax, sMin, sMax);
    }
    cout << hMin << hMax << sMin << sMax << endl;
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

    FaceRemover faceRemover;
    FingerCounter fingerCounter;
    Ptr<BackgroundSubtractor> backgroundRemover = createBackgroundSubtractorKNN(150,200.0,false);

    int counter = 0;
    while (true) {

        bool bSuccess = cap.read(frame); // read a new frame from video

        //Breaking the while loop if the frames cannot be captured
        if (!bSuccess || frame.empty()) {
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
        }

        //show the flipped frame in the created window
        flip(frame, frame, 1);
        frameOutput = frame.clone();

        skinDetector.drawSkinColorSampler(frameOutput);

        if (!skinDetector.getCalibrated()) {
            callback(frameOutput);
            if (calibrate){
                skinDetector.calibrate(frame);
                calibrate = false;
            }
        } else {
            //remove the face from the image using cascade
            faceRemover.removeFaces(frame);

            //Blur the frame
            Size kSize;
            kSize.height = 3;
            kSize.width = 3;
            double sigma = 0.3 * (3 / 2 - 1) + 0.8;
            GaussianBlur(frame, frame, kSize, sigma, 0.0, 4);

            backgroundRemover->apply(frame, bgMask);

            copyTo(frame, backgroundRemoved, bgMask);
            skinMask = skinDetector.getSkinMask(backgroundRemoved);
            copyTo(frame, newimg, skinMask);
            fingerCounterDebug = fingerCounter.findFingersCount(skinMask, frame);

            if (toDisplay == "skinMask") {
                callback(skinMask);
            } else if (toDisplay == "finger") {
                callback(frame);
            }

            backgroundRemoved = NULL;
            newimg = NULL;
        }
    }
}

void CaptureAndDetect::start(function<void(Mat)> callTo) {
    uthread = thread(&CaptureAndDetect::captureAndTrack, this);
    callback = callTo;
}

void CaptureAndDetect::stop() {
    uthread.join();
}

void CaptureAndDetect::calibrateColorPressed() {
    calibrate = true;
}

void CaptureAndDetect::displayImage(String display) {
    toDisplay = display;
}
