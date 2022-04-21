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
#include "QKeyEvent"
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
using namespace Gestro;

namespace Ui {
class ControllerScreen;
}

/**
 * @brief It sets up the GUI, initializes CaptureAndDetect, and DisplayControl
 *
 * Connects the GUI events to the appropriate functions, and connects the signals to the appropriate
 * slots
 *
 * @param parent The parent widget of the dialog.
 */
class ControllerScreen : public QDialog, public ControllerScreenCallbackInterface
{
    Q_OBJECT

public:
    /**
     * Construtor
     * @param parent
     */
    explicit ControllerScreen(QWidget *parent = 0);

    /**
    * The destructor for the ControllerScreen class.
    */
    ~ControllerScreen();
    void Callback_controls(FingerAndCoordinates finger);

    /**
    * It recieves the latest frame converts from BGR to RGB, then it converts the image to a QImage, and finally it sets the QImage to the
    * label
     *
    * @param dest the image to be displayed
        */
    void updateImage(Mat) override;

    /**
    * It updates the trackbars on the controller screen with the values passed in
    *
    * @param hmin minimum hue value
    * @param hmax Hue maximum value
    * @param smin minimum saturation value
    * @param smax The maximum value of the saturation channel.
    */
    void updateCalibratedTrackbar(int, int, int, int) override;

    /**
    * It takes two strings as arguments, and adds them to the table widget
    *
    * @param a The first parameter is the name of the function that is being called.
    * @param b the message to be displayed
    */
    void updateLogTable(String a, String b) override;

    /**
    * If the user presses the "B" key, then the calibrateBackground_clicked() function is called
    *
    * @param keypress the key that was pressed
    */
    void keyPressEvent(QKeyEvent*) override;

private:
    /** @brief A pointer to the ui class.*/
    Ui::ControllerScreen *ui;

    /** @brief Creating an instance of the CaptureAndDetect class.*/
    CaptureAndDetect captureAndDetect;

    /** @brief Opening a connection to the X server.*/
    Display *display = XOpenDisplay(NULL);

    /** @brief Creating an instance of the DisplayControl class. */
    DisplayControl displayControl = DisplayControl(display);

    /** @brief Getting the default screen of the display. */
    Screen *screen = DefaultScreenOfDisplay(display);

    /** @brief Creating an instance of the CustomSignals class. */
    CustomSignals signal;

    /** @brief A class that is used to store the enabled commands. */
    EnabledCommand enabledCommands;

     /**
    * It connects the GUI elements to the appropriate slots
    */
    void connectGuiEvents();

    /**
    * It connects the signals from the controller to the slots in the captureAndDetect class
    */
    void connectSignals();


public slots:

    /**
    * When the unprocessed feed button is clicked, the image view is changed to the unprocessed feed and the log table is
    * updated
    */
    void unprocessedFeed_clicked();

    /**
    * When the skinMask button is clicked, the imageViewChanged signal is emitted with the SKINMASK parameter, and the log
    * table is updated.
    */
    void skinMask_clicked();

    /**
    * It changes the image view to the finger counter
    */
    void detector_clicked();

    /**
    * When the calibrate button is clicked, the skin mask and detector buttons are enabled, the calibrate button is disabled,
    * the calibrate signal is emitted, the image view is changed to the skin mask, and the log table is updated
    */
    void calibrate_clicked();

    /**
    * It sets the calibration values for the signal
    */
    void setCalibrationValues();

    /**
    * It calls the calibrateBackground() function in the Signal class, and then updates the log table with a message
    */
    void calibrateBackground_clicked();


    /**
    * If the checkbox is checked, then the controlMouse variable is set to true, otherwise it is set to false
    */
    void enableMouse();

    /**
    * If the checkbox is checked, then the controlSpacebar variable is set to true, otherwise it is set to false
    */
    void enableSpaceBar();

    /**
    * If the checkbox is checked, then the command is enabled
    */
    void enableMinimizeWindow();

    /**
    * If the checkbox is checked, then the controlMoveWindow variable is set to true, otherwise it is set to false
    */
    void enableMoveWindow();

    /**
    * If the checkbox is checked, then the controlVolume variable is set to true, otherwise it is set to false
    */
    void enableVolume();
};

#endif // CONTROLLER_DIALOG_H
