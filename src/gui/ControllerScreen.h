#ifndef CONTROLLER_DIALOG_H
#define CONTROLLER_DIALOG_H

#include "ui_controller_dialog.h"
#include <QDialog>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTime>
#include "opencv2/opencv.hpp"
#include "CaptureAndDetect.h"
#include "DisplayControl.h"
#include "FingerAndCoordinates.h"
#include "CallbackInterface.h"

using namespace cv;
namespace Ui {
class ControllerScreen;
}

class ControllerScreen : public QDialog, public CallbackInterface
{
    Q_OBJECT

public:
    explicit ControllerScreen(QWidget *parent = 0);
    ~ControllerScreen();
    void Callback(Mat);
    void Callback_controls(FingerAndCoordinates finger);
    void updateImage(Mat) override;

private:
    Ui::ControllerScreen *ui;
    CaptureAndDetect captureAndDetect;
    Display *display = XOpenDisplay(NULL);
    DisplayControl displayControl = DisplayControl(display);
    Screen *screen = DefaultScreenOfDisplay(display);

public slots:
    void unprocessedFeed_clicked();
    void skinMask_clicked();
    void detector_clicked();
    void calibrate_clicked();
    void setCalibrationValues();

    void calibrateBackground_clicked();
};

#endif // CONTROLLER_DIALOG_H
