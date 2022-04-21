#ifndef GESTRO_CAPTUREANDDETECTINTERFACE_H
#define GESTRO_CAPTUREANDDETECTINTERFACE_H

#include "opencv2/opencv.hpp"
#include "FingerAndCoordinates.h"

using namespace cv;
using namespace GestureDetection;

namespace Gestro {
    /** @brief Callback interface for CaptureAndDetect */
    class CaptureAndDetectCallbackInterface {
    public:
        /** @brief virtual method to update newFrame */
        virtual void newFrame(Mat) = 0;

        /** @brief virtual method to add data to buffer */
        virtual void addToBuffer(FingerAndCoordinates) = 0;
    };
}

#endif //GESTRO_CAPTUREANDDETECTINTERFACE_H
