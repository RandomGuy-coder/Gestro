//
// Created by terrancewong on 20/02/2022.
//

#ifndef UBUNTU_GESTURECONTROL_FACEREMOVER_H
#define UBUNTU_GESTURECONTROL_FACEREMOVER_H

#include <opencv2/core/mat.hpp>

using namespace cv;
using namespace std;


class FaceRemover {
public:
    FaceRemover(void);
    void removeFaces(Mat &inputFrame);

};


#endif //UBUNTU_GESTURECONTROL_FACEREMOVER_H
