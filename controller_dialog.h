#ifndef CONTROLLER_DIALOG_H
#define CONTROLLER_DIALOG_H

#include <QDialog>
namespace Ui {
class controller_dialog;
}

class controller_dialog : public QDialog
{
    Q_OBJECT
    friend class TestController;
public:
    explicit controller_dialog(QWidget *parent = 0);
    ~controller_dialog();
    Ui::controller_dialog *ui;
private:

public slots:
    void pushbutton1_clicked();
    void pushbutton2_clicked();
    void pushbutton3_clicked();
    void pushbutton4_clicked();
private slots:

};

#endif // CONTROLLER_DIALOG_H
