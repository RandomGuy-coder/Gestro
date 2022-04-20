#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>

namespace Ui {
class StartScreen;
}

class StartScreen : public QWidget
{
    Q_OBJECT
    friend class TestController;
public:
    explicit StartScreen(QWidget *parent = 0);
    ~StartScreen();
    Ui::StartScreen *ui;

private:

public slots:
    void pushbutton_start_clicked();
    void pushbutton_software_intro_clicked();
    void pushbutton_team_intro_clicked();
private slots:

};

#endif // STARTSCREEN_H
