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
#include "boost/bind.hpp"
#include "opencv2/opencv.hpp"
#include "CaptureAndDetect.h"
#include "DisplayControl.h"
#include "FingerAndCoordinates.h"
#include "ControllerScreenCallbackInterface.h"
#include "CustomSignals.h"
#include "Commands.h"

using namespace cv;
using namespace std;
namespace Ui {
class ControllerScreen;
}

class ControllerScreen : public QDialog, public ControllerScreenCallbackInterface
{
    Q_OBJECT

public:
    explicit ControllerScreen(QWidget *parent = 0);
    ~ControllerScreen();
    void Callback_controls(FingerAndCoordinates finger);
    void updateImage(Mat) override;
    void updateCalibratedTrackbar(int, int, int, int) override;
    void updateLogTable(String a, String b) override;

private:
    Ui::ControllerScreen *ui;
    CaptureAndDetect captureAndDetect;
    Display *display = XOpenDisplay(NULL);
    DisplayControl displayControl = DisplayControl(display);
    Screen *screen = DefaultScreenOfDisplay(display);
    CustomSignals signal;
    void connectGuiEvents();
    void connectSignals();
    EnabledCommand enabledCommands;

public slots:
    void unprocessedFeed_clicked();
    void skinMask_clicked();
    void detector_clicked();
    void calibrate_clicked();
    void setCalibrationValues();
    void calibrateBackground_clicked();
    void enableMouse();
    void enableSpaceBar();
    void enableMinimizeWindow();
    void enableMoveWindow();
    void enableVolume();
};

#endif // CONTROLLER_DIALOG_H
