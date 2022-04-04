//
// Created by terrancewong on 20/02/2022.
//

#ifndef GESTRO_FACEREMOVER_H
#define GESTRO_FACEREMOVER_H

#include <opencv2/core/mat.hpp>

using namespace cv;
using namespace std;


class FaceRemover {
public:
    FaceRemover(void);
    void removeFaces(Mat &inputFrame);

};


#endif //GESTRO_FACEREMOVER_H
