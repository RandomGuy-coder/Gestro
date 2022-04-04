#include "ControllerScreen.h"
#include "ui_controller_dialog.h"
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QTime>
uint32_t operate_num = 0;
ControllerScreen::ControllerScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ControllerScreen)
{
    ui->setupUi(this);
    QImage *image2 = new QImage("C:/Users/jxrt/Desktop/GUI/QT_gui/QT_gui/picture.jpg");
    ui->label_show_pic->setPixmap(QPixmap::fromImage(*image2));
    ui->label_show_pic->show();
    QImage *image3 = new QImage("C:/Users/jxrt/Desktop/GUI/QT_gui/QT_gui/controll.jpg");
    ui->label_show_guide->setPixmap(QPixmap::fromImage(*image3));
    ui->label_show_guide->adjustSize();
    //ui->label_show_guide->show();
    ui->scrollArea->setWidget(ui->label_show_guide);
    connect(ui->unprocessed_feed,SIGNAL(clicked(bool)),this,SLOT(pushbutton1_clicked()));
    connect(ui->skin_mask,SIGNAL(clicked(bool)),this,SLOT(pushbutton2_clicked()));
    connect(ui->detector,SIGNAL(clicked(bool)),this,SLOT(pushbutton3_clicked()));
    connect(ui->calibrate,SIGNAL(clicked(bool)),this,SLOT(pushbutton4_clicked()));
}

ControllerScreen::~ControllerScreen()
{
    delete ui;
}

void ControllerScreen::pushbutton1_clicked()
{
    QTableWidgetItem *item;
    ui->tableWidget->setRowCount(operate_num+1);      //Set the number of table rows
    item = new QTableWidgetItem(QString::number(operate_num+1));
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,0,item);

    QString pushbutton_text = ui->unprocessed_feed->text();
    item = new QTableWidgetItem(pushbutton_text);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,1,item);


    item = new QTableWidgetItem("success");
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,2,item);

    QTime current_time = QTime::currentTime();

    item = new QTableWidgetItem(current_time.toString());
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,3,item);
    operate_num++;
}



void ControllerScreen::pushbutton2_clicked()
{
    QTableWidgetItem *item;
    ui->tableWidget->setRowCount(operate_num+1);      //Set the number of table rows
    item = new QTableWidgetItem(QString::number(operate_num+1));
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,0,item);

    QString pushbutton_text = ui->skin_mask->text();
    item = new QTableWidgetItem(pushbutton_text);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,1,item);


    item = new QTableWidgetItem("success");
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,2,item);

    QTime current_time = QTime::currentTime();

    item = new QTableWidgetItem(current_time.toString());
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,3,item);
    operate_num++;
}

void ControllerScreen::pushbutton3_clicked()
{
    QTableWidgetItem *item;
    ui->tableWidget->setRowCount(operate_num+1);      //Set the number of table rows
    item = new QTableWidgetItem(QString::number(operate_num+1));
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,0,item);

    QString pushbutton_text = ui->detector->text();
    item = new QTableWidgetItem(pushbutton_text);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,1,item);


    item = new QTableWidgetItem("success");
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,2,item);

    QTime current_time = QTime::currentTime();

    item = new QTableWidgetItem(current_time.toString());
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,3,item);
    operate_num++;
}



void ControllerScreen::pushbutton4_clicked()
{
    QTableWidgetItem *item;
    ui->tableWidget->setRowCount(operate_num+1);      //Set the number of table rows
    item = new QTableWidgetItem(QString::number(operate_num+1));
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,0,item);

    QString pushbutton_text = ui->calibrate->text();
    item = new QTableWidgetItem(pushbutton_text);
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,1,item);


    item = new QTableWidgetItem("success");
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,2,item);

    QTime current_time = QTime::currentTime();

    item = new QTableWidgetItem(current_time.toString());
    item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->tableWidget->setItem(operate_num,3,item);
}

void ControllerScreen::Callback(Mat dest){
    QImage image1 = QImage((uchar*) dest.data, dest.cols, dest.rows, dest.step, QImage::Format_RGB888);
    ui->label_show_pic->setPixmap(QPixmap::fromImage(image1));
}