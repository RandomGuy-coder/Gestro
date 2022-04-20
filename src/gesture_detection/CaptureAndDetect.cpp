#include "CaptureAndDetect.h"


CaptureAndDetect::CaptureAndDetect() {
}

void CaptureAndDetect::init(ControllerScreenCallbackInterface *interface, int screenWidth, int screenHeight, EnabledCommand *enabledCommand,
                            Resolution width, Resolution height) {
    capture.init(this, width, height);
    displayWidth = screenWidth;
    displayHeight = screenHeight;
    roi = Rect(width / 2, 0, width / 2, height / 2);
    callback = interface;
    capture.start();
    uthread = thread(&CaptureAndDetect::processFrame, this);
    commandThread = thread(&CaptureAndDetect::processCommands, this);
    palmClassifier = new CascadeClassifier("../src/resources/cascades/rpalm.xml");
    fingerCounter.ConnectCallback(this);
    commands = enabledCommand;
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
                    if (fingerAndCoordinates.command != NO_FINGER) {
                        detectedFingers.push(fingerAndCoordinates);
                    }
                    frame2.copyTo(frame(roi));
                    callback->updateImage(frame);
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

            switch(toProcess.command) {
                case MOUSE_MOVE:
                    if(commands->controlMouse) {
                        controlInterface->doMouseMove(displayWidth / ((float) roi.width / (float) toProcess.x),
                                                      displayHeight / ((float) roi.height / (float) toProcess.y));
                    }
                    break;
                case MOUSE_CLICK:
                    if(commands->controlMouse) {
                        controlInterface->doButtonPress(1);
                    }
                    break;
                case VOLUME_UP:
                    if(commands->controlVolume) {
                        controlInterface->doUnmute();
                        controlInterface->doIncreaseVolume();
                    }
                    break;
                case VOLUME_DOWN:
                    if(commands->controlVolume) {
                        controlInterface->doReduceVolume();
                    }
                    break;
                case MUTE_UNMUTE:
                    if(commands->controlVolume) {
                        controlInterface->doMuteUnmute();
                    }
                    break;
                case MOVE_WINDOW:
                    if(commands->controlMoveWindow) {
                        controlInterface->doWindowMove(displayWidth / ((float) roi.width / (float) toProcess.x),
                                                       displayHeight / ((float) roi.height / (float) toProcess.y));
                    }
                    break;
                case MINIMIZE_WINDOW:
                    if(commands->controlMinimizeWindow) {
                        controlInterface->doWindowMinimize();
                    }
                    break;
                case PRESS_SPACE:
                    if(commands->controlSpacebar) {
                        controlInterface->doKeyPress(32);
                    }
                    break;
            }
            detectedFingers.pop();
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
    if(!features.empty()) {
        return true;
    } else {
        return false;
    }
}

