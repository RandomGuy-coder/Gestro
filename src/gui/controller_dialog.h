#ifndef CONTROLLER_DIALOG_H
#define CONTROLLER_DIALOG_H

#include <QDialog>

namespace Ui {
class controller_dialog;
}

class controller_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit controller_dialog(QWidget *parent = 0);
    ~controller_dialog();

private:
    Ui::controller_dialog *ui;
public slots:
    void pushbutton1_clicked();
    void pushbutton2_clicked();
    void pushbutton3_clicked();
    void pushbutton4_clicked();
};

#endif // CONTROLLER_DIALOG_H
