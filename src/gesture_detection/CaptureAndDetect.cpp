#include "CaptureAndDetect.h"

CaptureAndDetect::CaptureAndDetect() {
}

void CaptureAndDetect::init(CallbackInterface* interface, Resolution width, Resolution height){
    capture.init(this, width, height);
    roi = Rect(width/2, 0, width/2, height/2);
    callback = interface;
    capture.start();
}

void CaptureAndDetect::calibrateValues(int hMin, int hMax, int sMin, int sMax) {
    if(skinDetector.getCalibrated()) {
        skinDetector.calibrateValues(hMin, hMax, sMin, sMax);
    }
}

void CaptureAndDetect::newFrame(Mat frame){
    Mat frameOutput, skinMask, bgMask, fingerCounterDebug, backgroundRemoved, newimg;

    flip(frame, frame, 1);
    currentFrame = frame.clone();
    rectangle(frame, roi, Scalar(0,255,255));
    frameOutput = frame(roi);
    Mat frame2 = frameOutput.clone();
    skinDetector.drawSkinColorSampler(frameOutput);
    frameOutput.copyTo(frame(roi));

    if (!skinDetector.getCalibrated()) {
        callback->updateImage(frame);
    } else if (skinDetector.getCalibrated() && !backgroundCalibrated) {
        Mat FrameToUpdate;
        copyTo(frame2, FrameToUpdate, skinDetector.getSkinMask(frame2));
        FrameToUpdate.copyTo(currentFrame(roi));
        callback->updateImage(currentFrame);
    } else if(toDisplay == UNPROCESSED) {
        callback->updateImage(frame);
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

        if (toDisplay == SKINMASK) {
            newimg.copyTo(frame(roi));
            callback->updateImage(frame);
        } else if (toDisplay == DETECTED) {
            fingerAndCoordinates = fingerCounter.findFingersCount(skinMask, frame2);
            frame2.copyTo(frame(roi));
            callback->updateImage(frame);
            if(fingerAndCoordinates.count!=0){
                callback->fingerDetected(fingerAndCoordinates);
            }
        }
        backgroundRemoved = NULL;
        newimg = NULL;
    }
}

void CaptureAndDetect::calibrateColorPressed() {
    vector<int> a = skinDetector.calibrate(currentFrame);
    callback->updateCalibratedTrackbar(a[0],a[1],a[2],a[3]);
}

void CaptureAndDetect::calibrateBackgroundRemover() {
    backgroundRemover = createBackgroundSubtractorMOG2(10, 30);
    backgroundCalibrated = true;
}

void CaptureAndDetect::displayImage(int feed) {
    toDisplay = feed;
}

