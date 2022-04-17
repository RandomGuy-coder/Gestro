#include "Capture.h"

Capture::Capture() {}

void Capture::init(DetectInterface *interface, int width, int height) {
    this->width = width;
    this->height = height;
    callback = interface;
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
    VideoCapture capture(0);
    if(!capture.isOpened()){
        capture.open(0);
    }
    if(width){
        capture.set(3, width);
    }
    if(height){
        capture.set(4,height);
    }
    capture.set(6, VideoWriter::fourcc('M','J','P','G'));

    while(running){
        Mat frame;
        try{
            cout << capture.isOpened() << endl;
            capture.read(frame); // read a new frame from video
            //Breaking the while loop if the frames cannot be captured
            if (frame.empty()) {
                cerr << "Video camera is disconnected" << endl;
                running = false;
            }
            callback->newFrame(frame);
        } catch (...) {
            cerr << "Error capturing image" << endl;
            running = false;
        }
    }
}
