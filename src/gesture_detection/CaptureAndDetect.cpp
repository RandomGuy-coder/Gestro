#include "CaptureAndDetect.h"


CaptureAndDetect::CaptureAndDetect() {
}

void CaptureAndDetect::init(ControllerScreenCallbackInterface *interface, Resolution width, Resolution height, int screenWidth, int screenHeight) {
    capture.init(this, width, height);
    roi = Rect(width / 2, 0, width / 2, height / 2);
    callback = interface;
    capture.start();
    uthread = thread(&CaptureAndDetect::processFrame, this);
    palmClassifier = new CascadeClassifier("../../src/resources/cascades/rpalm.xml");
    fingerCounter.ConnectCallback(this);
}

void CaptureAndDetect::calibrateValues(int hMin, int hMax, int sMin, int sMax) {
    if (skinDetector.getCalibrated()) {
        skinDetector.calibrateValues(hMin, hMax, sMin, sMax);
    }
}


void CaptureAndDetect::newFrame(Mat incomingFrame) {
    this->recievedFrame = incomingFrame;
    frameRecieved = true;
}


void CaptureAndDetect::processFrame() {

//    CascadeClassifier fist_classifier("../Resources/fist.xml" );
    while (capture.running) {
        if (frameRecieved) {
            frameRecieved = false;
            Mat frame = recievedFrame.clone();
            Mat frameOutput, skinMask, bgMask, fingerCounterDebug, backgroundRemoved, newimg;
            flip(frame, frame, 1);
            currentFrame = frame.clone();
            rectangle(frame, roi, Scalar(0, 255, 255));
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
            } else if (toDisplay == UNPROCESSED) {
                callback->updateImage(frame);
            } else if (backgroundCalibrated) {
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
                    if (fingerAndCoordinates.count != 0) {
                        callback->fingerDetected(fingerAndCoordinates);
                    }
                }
                backgroundRemoved = NULL;
                newimg = NULL;
            }
        }
    }
}

void CaptureAndDetect::processCommands() {
    while(capture.running){
        if(!detectedFingers.empty()) {
            FingerAndCoordinates toProcess = detectedFingers.front();

            if(toProcess.count == 1) {
            int x = screen->width/((float)640/(float)finger.x);
            int y = screen->height/((float)360/(float)finger.y);
            displayControl.moveMouseTo(x, y);
            if(finger.click){
                displayControl.pressButton(1);
            }
            } else if(finger.count == 2) {
            if(!finger.click) {
                displayControl.muteAndUnmute();
            } else {
                displayControl.unmute();
            if(finger.distance > 0) {
                cout << "increasing" << endl;
                displayControl.increaseVolume();
            }
            else {
                displayControl.reduceVolume();
            }
            }
        } else if(finger.count == 3) {
            displayControl.minimizeWindow();
        } else if(finger.count == 4 ) {
            displayControl.pressKey(65);
        }
        }
    }
}


void CaptureAndDetect::calibrateColorPressed() {
    vector<int> a = skinDetector.calibrate(currentFrame);
    callback->updateCalibratedTrackbar(a[0], a[1], a[2], a[3]);
}

void CaptureAndDetect::calibrateBackgroundRemover() {
    backgroundRemover = createBackgroundSubtractorMOG2(10, 30);
    backgroundCalibrated = true;
}

void CaptureAndDetect::displayImage(int feed) {
    toDisplay = feed;
}

void CaptureAndDetect::connectControlCallback(DisplayControlCallbackInterface *interface) {
    controlInterface = interface;
}

void CaptureAndDetect::addToBuffer(FingerAndCoordinates finger) {
    detectedFingers.push(finger);
}

bool CaptureAndDetect::checkForPalm() {
    vector<cv::Rect> features;
    palmClassifier->detectMultiScale(currentFrame, features, 1.1, 5, 0 | CASCADE_SCALE_IMAGE, Size(30,30));
    if(features.size() != NULL) {
        cout << "palm" << endl;
        return true;
    } else {
        return false;
    }
}

