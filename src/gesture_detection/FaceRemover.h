#ifndef GESTRO_FACEREMOVER_H
#define GESTRO_FACEREMOVER_H

#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;


class FaceRemover {
public:
    FaceRemover(void);
    void removeFaces(Mat &inputFrame);

};


#endif //GESTRO_FACEREMOVER_H
