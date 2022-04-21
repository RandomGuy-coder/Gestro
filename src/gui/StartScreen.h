#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "../gesture_detection/CaptureAndDetect.h"
#include "thread"

namespace Ui {
class StartScreen;
}
/**
 * @brief It sets up the start screen.
 */
class StartScreen : public QWidget
{
    Q_OBJECT

public:

    /**
    * It sets up the start screen.
    *
    * @param parent The parent widget of the new widget. If the widget is a window, the parent must be 0.
    */
    explicit StartScreen(QWidget *parent = 0);

    /**
    * The destructor for the StartScreen class.
    */
    ~StartScreen();

private:
    /** @brief A pointer to the UI of the StartScreen class.*/
    Ui::StartScreen *ui;

public slots:

    /**
    * When the user clicks the start button, the controller screen is shown and the start screen is hidden
    */
    void pushbutton_start_clicked();

    /**
    * A function that is called when the user clicks on the "Software Introduction" button.
    */
    void pushbutton_software_intro_clicked();

    /**
    * A function that is called when the user clicks on the "About Us" button.
    */
    void pushbutton_team_intro_clicked();
};

#endif // WIDGET_H
