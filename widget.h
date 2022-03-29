#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
public slots:
    void pushbutton_start_clicked();
    void pushbutton_software_intro_clicked();
    void pushbutton_team_intro_clicked();
};

#endif // WIDGET_H
