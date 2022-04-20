#ifndef CONTROLLERSCREEN_H
#define CONTROLLERSCREEN_H

#include <QDialog>
#include <QDialog>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTime>
namespace Ui {
class ControllerScreen;
}

class ControllerScreen : public QDialog
{
    Q_OBJECT
    friend class TestController;
public:
    explicit ControllerScreen(QWidget *parent = 0);
    ~ControllerScreen();
    Ui::ControllerScreen *ui;
private:

public slots:
    void pushbutton1_clicked();
    void pushbutton2_clicked();
    void pushbutton3_clicked();
    void pushbutton4_clicked();
private slots:

};

#endif // CONTROLLERSCREEN_H
