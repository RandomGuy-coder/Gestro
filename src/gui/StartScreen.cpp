#include "StartScreen.h"
#include "ui_widget.h"
#include <QImage>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include "ControllerScreen.h"

StartScreen::StartScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);
    QImage *image1 = new QImage("../src/resources/img/Logo.png");
    QFile inputFile("../src/resources/text/instructions.txt");
    inputFile.open(QIODevice::ReadOnly);
    QTextStream in(&inputFile);
    QString line = in.readAll();
    inputFile.close();
    QFile inputFile2("../src/resources/text/about.txt");
    inputFile2.open(QIODevice::ReadOnly);
    QTextStream in2(&inputFile2);
    QString line2 = in2.readAll();
    inputFile2.close();
    ui->textBrowser_software_intro->setPlainText(line);
    ui->textBrowser_team_intro->setPlainText(line2);
    ui->label_logo->setPixmap(QPixmap::fromImage(*image1));
    ui->label_logo->show();
    ui->textBrowser_software_intro->setHidden(true);
    ui->textBrowser_team_intro->setHidden(true);
    ui->pushButton_start->setStyleSheet("background-color: rgb(85, 170, 255);color:white");
    ui->pushButton_software_into->setStyleSheet("background-color: rgb(85, 170, 255);color:white");
    ui->pushButton_team_intro->setStyleSheet("background-color: rgb(85, 170, 255);color:white");
    connect(ui->pushButton_start,SIGNAL(clicked(bool)),this,SLOT(pushbutton_start_clicked()));
    connect(ui->pushButton_software_into,SIGNAL(clicked(bool)),SLOT(pushbutton_software_intro_clicked()));
    connect(ui->pushButton_team_intro,SIGNAL(clicked(bool)),this,SLOT(pushbutton_team_intro_clicked()));

}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::pushbutton_start_clicked()
{
    ControllerScreen *controller_info = new ControllerScreen();
    controller_info->show();
    this->hide();
}

void StartScreen::pushbutton_software_intro_clicked()
{
    QColor bgcolor;
    bgcolor = ui->pushButton_software_into->palette().color(QPalette::Background);
    if(bgcolor == QColor(85, 170, 255))
    {
        ui->textBrowser_software_intro->show();
        ui->pushButton_software_into->setStyleSheet("background-color: rgb(0, 0, 0);color:white");
    }
    else
    {
        ui->textBrowser_software_intro->hide();
        ui->pushButton_software_into->setStyleSheet("background-color: rgb(85, 170, 255);color:white");
    }
}

void StartScreen::pushbutton_team_intro_clicked()
{
    QColor bgcolor;
    bgcolor = ui->pushButton_team_intro->palette().color(QPalette::Background);
    if(bgcolor == QColor(85, 170, 255))
    {
        ui->textBrowser_team_intro->show();
        ui->pushButton_team_intro->setStyleSheet("background-color: rgb(0, 0, 0);color:white");
    }
    else
    {
        ui->textBrowser_team_intro->hide();
        ui->pushButton_team_intro->setStyleSheet("background-color: rgb(85, 170, 255);color:white");
    }

}
