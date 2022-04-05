#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../gesture_detection/CaptureAndDetect.h"
#include "thread"

namespace Ui {
class StartScreen;
}

class StartScreen : public QWidget
{
    Q_OBJECT

public:
    explicit StartScreen(QWidget *parent = 0);
    ~StartScreen();

private:
    Ui::StartScreen *ui;

public slots:
    void pushbutton_start_clicked();
    void pushbutton_software_intro_clicked();
    void pushbutton_team_intro_clicked();
};

#endif // WIDGET_H
