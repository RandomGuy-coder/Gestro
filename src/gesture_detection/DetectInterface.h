//
// Created by tushar on 17/04/22.
//

#ifndef TEST_DETECTINTERFACE_H
#define TEST_DETECTINTERFACE_H

using namespace cv;

class DetectInterface{
public:
    virtual void newFrame(Mat) = 0;
};

#endif //TEST_DETECTINTERFACE_H
