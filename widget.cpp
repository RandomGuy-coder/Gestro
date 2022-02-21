#include "widget.h"
#include "ui_widget.h"
#include <QImage>
#include <QPixmap>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    show_picture();
}

Widget::~Widget()
{
    delete ui;
}
void Widget::show_picture()
{
    QImage *image1 = new QImage("C:/Users/bbz/Desktop/GUI/control_gui/control_gui/control_gui/images/show.jpg");
    ui->label_show->setPixmap(QPixmap::fromImage(*image1));
    ui->label_show->show();

    QImage *image2 = new QImage("C:/Users/bbz/Desktop/GUI/control_gui/control_gui/control_gui/images/guide.jpg");
    ui->label_guide->setPixmap(QPixmap::fromImage(*image2));
    ui->label_guide->show();

}
