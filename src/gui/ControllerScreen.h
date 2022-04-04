#ifndef CONTROLLER_DIALOG_H
#define CONTROLLER_DIALOG_H

#include <QDialog>
#include "opencv2/opencv.hpp"
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
public slots:
    void pushbutton1_clicked();
    void pushbutton2_clicked();
    void pushbutton3_clicked();
    void pushbutton4_clicked();

};

#endif // CONTROLLER_DIALOG_H
