//
// Created by terrancewong on 20/02/2022.
//

#include "FaceRemover.h"
#include "opencv2/opencv.hpp"

String faceClassifierFileName = "../Resources/haarcascade_frontalface_alt.xml";
CascadeClassifier faceCascadeClassifier;

FaceRemover::FaceRemover(void) {
    if (!faceCascadeClassifier.load(faceClassifierFileName))
        throw runtime_error("can't load file " + faceClassifierFileName);
}

void FaceRemover::removeFaces(Mat &inputFrame) {
    vector<Rect> faces;
    Mat frameGray;

    cvtColor(inputFrame, frameGray, COLOR_BGR2GRAY);
//    equalizeHist(frameGray, frameGray);

    faceCascadeClassifier.detectMultiScale(frameGray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(120, 120));

    for (size_t i = 0; i < faces.size(); i++) {
        rectangle(
                inputFrame,
                faces[i],
                Scalar(0, 0, 0),
                -1
        );
    }
}

Rect getFaceRect(Mat inputFrame) {
    vector<Rect> faceRectangles;
    Mat inputFrameGray;

    cvtColor(inputFrame, inputFrameGray, COLOR_BGR2GRAY);
    equalizeHist(inputFrameGray, inputFrameGray);

    faceCascadeClassifier.detectMultiScale(inputFrameGray, faceRectangles, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(120, 120));

    if (faceRectangles.size() > 0)
        return faceRectangles[0];
    else
        return Rect(0, 0, 1, 1);
}