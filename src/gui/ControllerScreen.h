#ifndef CONTROLLER_DIALOG_H
#define CONTROLLER_DIALOG_H

#include <QDialog>
#include "opencv2/opencv.hpp"
#include "CaptureAndDetect.h"
using namespace cv;
namespace Ui {
class ControllerScreen;
}

class ControllerScreen : public QDialog
{
    Q_OBJECT

public:
    explicit ControllerScreen(QWidget *parent = 0);
    ~ControllerScreen();
    void Callback(Mat);

private:
    Ui::ControllerScreen *ui;
    CaptureAndDetect captureAndDetect;

public slots:
    void unprocessedFeed_clicked();
    void skinMask_clicked();
    void detector_clicked();
    void calibrate_clicked();
    void setCalibrationValues();
};

#endif // CONTROLLER_DIALOG_H
