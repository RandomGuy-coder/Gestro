//
// Created by terrancewong on 20/02/2022.
//

#ifndef UBUNTU_GESTURECONTROL_BACKGROUNDREMOVER_H
#define UBUNTU_GESTURECONTROL_BACKGROUNDREMOVER_H

#include <opencv2/core/mat.hpp>

using namespace cv;
using namespace std;

class BackgroundRemover {
private:
    Mat background;
    bool calibrated = false;

    Mat getForegroundMask(Mat input);
    void removeBackground(Mat input, Mat background);

public:
    BackgroundRemover(void);
    void calibrate(Mat input);
    Mat getForeground(Mat input);
    bool getCalibrated() {return calibrated;}
};

#endif //UBUNTU_GESTURECONTROL_BACKGROUNDREMOVER_H
