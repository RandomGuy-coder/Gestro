#include "ControllerScreen.h"

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
    captureAndDetect.init(this);
    captureAndDetect.connectControlCallback(&displayControl);
    ui->scrollArea->setWidget(ui->label_show_guide);
    connectGuiEvents();
    connectSignals();
    ui->hMinValue->setText(QString::number(ui->hMinSlider->value()));
    ui->hMaxValue->setText(QString::number(ui->hMaxSlider->value()));
    ui->sMinValue->setText(QString::number(ui->sMinSlider->value()));
    ui->sMaxValue->setText(QString::number(ui->sMaxSlider->value()));
    ui->skin_mask->setEnabled(false);
    ui->detector->setEnabled(false);

}

void ControllerScreen::connectSignals() {
    signal.imageViewChanged.connect(boost::bind(&CaptureAndDetect::displayImage, &captureAndDetect, _1));
    signal.calibrateBackground.connect(boost::bind(&CaptureAndDetect::calibrateBackgroundRemover, &captureAndDetect));
    signal.calibrateValues.connect(boost::bind(&CaptureAndDetect::calibrateValues, &captureAndDetect,_1,_2,_3,_4));
    signal.calibrate.connect(boost::bind(&CaptureAndDetect::calibrateColorPressed, &captureAndDetect));
}

void ControllerScreen::connectGuiEvents() {
    connect(ui->unprocessed_feed, SIGNAL(clicked(bool)), this, SLOT(unprocessedFeed_clicked()));
    connect(ui->skin_mask, SIGNAL(clicked(bool)), this, SLOT(skinMask_clicked()));
    connect(ui->detector, SIGNAL(clicked(bool)), this, SLOT(detector_clicked()));
    connect(ui->calibrate, SIGNAL(clicked(bool)), this, SLOT(calibrate_clicked()));
    connect(ui->hMinSlider, SIGNAL(valueChanged(int)), this, SLOT(setCalibrationValues()));
    connect(ui->hMaxSlider, SIGNAL(valueChanged(int)), this, SLOT(setCalibrationValues()));
    connect(ui->sMinSlider, SIGNAL(valueChanged(int)), this, SLOT(setCalibrationValues()));
    connect(ui->sMaxSlider, SIGNAL(valueChanged(int)), this, SLOT(setCalibrationValues()));
    connect(ui->calibrateROI, SIGNAL(clicked(bool)), this, SLOT(calibrateBackground_clicked()));
}

ControllerScreen::~ControllerScreen()
{
    delete ui;
}

void ControllerScreen::unprocessedFeed_clicked()
{
    signal.imageViewChanged(UNPROCESSED);
    updateLogTable("Showing Unprocessed Feed", "SUCCESS");
}

void ControllerScreen::skinMask_clicked()
{
    signal.imageViewChanged(SKINMASK);
    updateLogTable("Showing Skin Mask", "SUCCESS");
}

void ControllerScreen::detector_clicked()
{
    signal.imageViewChanged(DETECTED);
    updateLogTable("Showing Finger Counter", "SUCCESS");
}

void ControllerScreen::calibrate_clicked()
{
    ui->skin_mask->setEnabled(true);
    ui->detector->setEnabled(true);
    ui->calibrate->setEnabled(false);
    signal.calibrate();
    signal.imageViewChanged(SKINMASK);
    updateLogTable("Calibration", "SUCCESS");
}

void ControllerScreen::calibrateBackground_clicked(){
    signal.calibrateBackground();
    updateLogTable("Background calibration", "SUCCESS");
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

    signal.calibrateValues(hMin, hMax, sMin, sMax);
}

void ControllerScreen::updateImage(Mat dest) {
    cvtColor(dest,dest, COLOR_BGR2RGB);
    QImage image1 = QImage((uchar*) dest.data, dest.cols, dest.rows, dest.step, QImage::Format_RGB888);
    ui->label_show_pic->setPixmap(QPixmap::fromImage(image1));
}

void ControllerScreen::updateCalibratedTrackbar(int hmin, int hmax, int smin, int smax) {
    ui->hMinSlider->setValue(hmin);
    ui->hMaxSlider->setValue(hmax);
    ui->sMinSlider->setValue(smin);
    ui->sMaxSlider->setValue(smax);
}

void ControllerScreen::updateLogTable(String a, String b) {
    QTime current_time = QTime::currentTime();
    int currentRow = ui->tableWidget->rowCount();
    ui->tableWidget->setRowCount(currentRow + 1);
    ui->tableWidget->setItem(currentRow,0,new QTableWidgetItem(QString::number(currentRow+1)));
    ui->tableWidget->setItem(currentRow,1,new QTableWidgetItem(QString::fromStdString(a)));
    ui->tableWidget->setItem(currentRow,2, new QTableWidgetItem(QString::fromStdString(b)));
    ui->tableWidget->setItem(currentRow,3, new QTableWidgetItem(current_time.toString()));
}

void ControllerScreen::fingerDetected(FingerAndCoordinates finger) {
//    if(finger.count == 1) {
//        int x = screen->width/((float)640/(float)finger.x);
//        int y = screen->height/((float)360/(float)finger.y);
//        displayControl.moveMouseTo(x, y);
//        if(finger.click){
//            displayControl.pressButton(1);
//        }
//    } else if(finger.count == 2) {
//        if(!finger.click) {
//            displayControl.muteAndUnmute();
//        } else {
//            displayControl.unmute();
//            if(finger.distance > 0) {
//                cout << "increasing" << endl;
//                displayControl.increaseVolume();
//            }
//            else {
//                displayControl.reduceVolume();
//            }
//        }
//    } else if(finger.count == 3) {
//        displayControl.minimizeWindow();
//    } else if(finger.count == 4 ) {
//        displayControl.pressKey(65);
//    }
}
