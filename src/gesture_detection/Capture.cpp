#include "Capture.h"

Capture::Capture() {}

void Capture::init(CaptureAndDetectCallbackInterface *interface, int width, int height) {
    capture = new VideoCapture(0);
    if(!capture->isOpened()){
        capture->open(0);
    }
    if(width){
        capture->set(3, width);
    }
    if(height){
        capture->set(4,height);
    }
    capture->set(6, VideoWriter::fourcc('M','J','P','G'));
    callback = interface;
    capture->read(frame);
    callback->newFrame(frame);
}

void Capture::start() {
    running = true;
    uthread = thread(&Capture::imageCap, this);
}

void Capture::stop() {
    running = false;
    uthread.join();
}

void Capture::imageCap() {
    while(running){
        try{
            capture->read(frame); // read a new frame from video
            //Breaking the while loop if the frames cannot be captured
            if (frame.empty()) {
                cerr << "Video camera is disconnected" << endl;
                running = false;
                break;
            }
            callback->newFrame(frame);
        } catch (...) {
            cerr << "Error capturing image" << endl;
            running = false;
        }
    }
}
