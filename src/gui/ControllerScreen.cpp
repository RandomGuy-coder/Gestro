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
    captureAndDetect.start(std::bind(&ControllerScreen::Callback, this, std::placeholders::_1));
    connect(ui->unprocessed_feed,SIGNAL(clicked(bool)),this,SLOT(unprocessedFeed_clicked()));
    connect(ui->skin_mask,SIGNAL(clicked(bool)),this,SLOT(skinMask_clicked()));
    connect(ui->detector,SIGNAL(clicked(bool)),this,SLOT(detector_clicked()));
    connect(ui->calibrate,SIGNAL(clicked(bool)),this,SLOT(calibrate_clicked()));
    connect(ui->hMinSlider, SIGNAL(valueChanged(int)), this, SLOT(setCalibrationValues()));
    connect(ui->hMaxSlider, SIGNAL(valueChanged(int)), this, SLOT(setCalibrationValues()));
    connect(ui->sMinSlider, SIGNAL(valueChanged(int)), this, SLOT(setCalibrationValues()));
    connect(ui->sMaxSlider, SIGNAL(valueChanged(int)), this, SLOT(setCalibrationValues()));
    ui->hMinValue->setText(QString::number(ui->hMinSlider->value()));
    ui->hMaxValue->setText(QString::number(ui->hMaxSlider->value()));
    ui->sMinValue->setText(QString::number(ui->sMinSlider->value()));
    ui->sMaxValue->setText(QString::number(ui->sMaxSlider->value()));
    ui->skin_mask->setEnabled(false);
    ui->detector->setEnabled(false);

}

ControllerScreen::~ControllerScreen()
{
    delete ui;
}

void ControllerScreen::unprocessedFeed_clicked()
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



void ControllerScreen::skinMask_clicked()
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
    captureAndDetect.displayImage("skinMask");
}

void ControllerScreen::detector_clicked()
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
    captureAndDetect.displayImage("finger");
}



void ControllerScreen::calibrate_clicked()
{
    ui->skin_mask->setEnabled(true);
    ui->detector->setEnabled(true);
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
    ui->calibrate->setEnabled(false);
    captureAndDetect.calibrateColorPressed();
}

void ControllerScreen::Callback(Mat dest){
    cvtColor(dest,dest, COLOR_BGR2RGB);
    QImage image1 = QImage((uchar*) dest.data, dest.cols, dest.rows, dest.step, QImage::Format_RGB888);
    ui->label_show_pic->setPixmap(QPixmap::fromImage(image1));
}

void ControllerScreen::setCalibrationValues() {
    int hMin = ui->hMinSlider->value();
    int hMax = ui->hMaxSlider->value();
    int sMin = ui->sMinSlider->value();
    int sMax = ui->sMaxSlider->value();
    ui->hMinValue->setText(QString::number(hMin));
    ui->hMaxValue->setText(QString::number(hMax));
    ui->sMinValue->setText(QString::number(sMin));
    ui->sMaxValue->setText(QString::number(sMax));

    captureAndDetect.calibrateValues(hMin, hMax, sMin, sMax);
}
