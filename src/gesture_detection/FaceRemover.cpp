#include "FaceRemover.h"

String faceClassifierFileName = "../../src/resources/cascades/haarcascade_frontalface_alt.xml";
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