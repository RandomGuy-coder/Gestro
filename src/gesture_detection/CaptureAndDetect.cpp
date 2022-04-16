#include "CaptureAndDetect.h"

using namespace std;
using namespace cv;

CaptureAndDetect::CaptureAndDetect(void){
}

void CaptureAndDetect::calibrateValues(int hMin, int hMax, int sMin, int sMax) {
    if(skinDetector.getCalibrated()) {
        skinDetector.calibrateValues(hMin, hMax, sMin, sMax);
    }
}

void CaptureAndDetect::captureAndTrack() {

    VideoCapture cap(0);

    if(!cap.isOpened()){
        cerr<<"cannot open cam" <<endl;
    }

    cap.set(3, 1280);
    cap.set(4,720);
    roi = Rect(1280/2, 0, 1280/2, 720/2);
    cap.set(6, VideoWriter::fourcc('M','J','P','G'));
    Mat frame, frameOutput, skinMask, bgMask, fingerCounterDebug, backgroundRemoved, newimg;

    FingerCounter fingerCounter;

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
        currentFrame = frame.clone();
        rectangle(frame, roi, Scalar(0,255,255));
        frameOutput = frame(roi);
        Mat frame2 = frameOutput.clone();
        skinDetector.drawSkinColorSampler(frameOutput);
        frameOutput.copyTo(frame(roi));

        if (!skinDetector.getCalibrated()) {
            interface->updateImage(frame);
        } else if (skinDetector.getCalibrated() && !backgroundCalibrated) {
            Mat FrameToUpdate;
            copyTo(frame2, FrameToUpdate, skinDetector.getSkinMask(frame2));
            FrameToUpdate.copyTo(currentFrame(roi));
            interface->updateImage(currentFrame);
        }
        else if(toDisplay == "unprocessed") {
            interface->updateImage(frame);
        } else if(backgroundCalibrated){
            //Blur the frame
            Size kSize;
            kSize.height = 3;
            kSize.width = 3;
            double sigma = 0.3 * (3 / 2 - 1) + 0.8;
            GaussianBlur(frame2, frame2, kSize, sigma, 0.0, 4);

            backgroundRemover->apply(frame2, bgMask, 0);

            copyTo(frame2, backgroundRemoved, bgMask);
            skinMask = skinDetector.getSkinMask(backgroundRemoved);
            copyTo(backgroundRemoved, newimg, skinMask);

            if (toDisplay == "skinMask") {
                newimg.copyTo(frame(roi));
                interface->updateImage(frame);
            } else if (toDisplay == "detect") {
                fingerAndCoordinates = fingerCounter.findFingersCount(skinMask, frame2);
                frame2.copyTo(frame(roi));
                interface->updateImage(frame);
                if(fingerAndCoordinates.count!=0){
                    interface->fingerDetected(fingerAndCoordinates);
                }
            }
            backgroundRemoved = NULL;
            newimg = NULL;
        }
    }
}

void CaptureAndDetect::start() {
    uthread = thread(&CaptureAndDetect::captureAndTrack, this);
}

void CaptureAndDetect::stop() {
    uthread.join();
}

void CaptureAndDetect::calibrateColorPressed() {
    vector<int> a = skinDetector.calibrate(currentFrame);
    interface->updateCalibratedTrackbar(a[0],a[1],a[2],a[3]);
}

void CaptureAndDetect::calibrateBackgroundRemover() {
    backgroundRemover = createBackgroundSubtractorMOG2(10, 30);
    backgroundCalibrated = true;
}

void CaptureAndDetect::displayImage(String display) {
    toDisplay = display;
}

void CaptureAndDetect::connectCallback(CallbackInterface *cb) {
    interface= cb;
}

