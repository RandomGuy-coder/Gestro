#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    friend class TestController;
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    Ui::Widget *ui;

private:

public slots:
    void pushbutton_start_clicked();
    void pushbutton_software_intro_clicked();
    void pushbutton_team_intro_clicked();
private slots:

};

#endif // WIDGET_H
