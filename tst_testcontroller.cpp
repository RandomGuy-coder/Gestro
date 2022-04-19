#include <QtTest>
#include <QCoreApplication>
#include "ui_widget.h"
#include "widget.h"
#include "controller_dialog.h"
#include "ui_controller_dialog.h"
// add necessary includes here

class TestController : public QObject
{
    Q_OBJECT

public:
    TestController();
    ~TestController();
     Widget  login;
     controller_dialog dialog;
private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_Instructions();
    void test_Aboutus();
    void test_Control_volume();
    void test_Control_brightness();
    void test_Control_switching();
    void test_Control_pause();
    void test_Control_feed();
    void test_Control_Mask();
    void test_Control_Detector();
    void test_Control_Calibrate();
    void test_Control_Mouse();
};

TestController::TestController()
{

}

TestController::~TestController()
{

}

void TestController::initTestCase()
{
    login.show();
    dialog.show();
}

void TestController::cleanupTestCase()
{

}

void TestController::test_Instructions()
{
       QCOMPARE(login.ui->textBrowser_software_intro->toPlainText(),"Instructions\n");//Test the default text for compliance

       //Test whether the length function of qtextbrowser changes when the button is pressed
       QSize oldLength=login.ui->textBrowser_software_intro->size();
       QTest::mouseClick(login.ui->pushButton_software_into,Qt::LeftButton);
       QSize newLength=login.ui->textBrowser_software_intro->size();
       QVERIFY((newLength.width()-oldLength.width())>0);
       //It should get longer

}
void TestController::test_Aboutus()
{

       QCOMPARE(login.ui->textBrowser_team_intro->toPlainText(),"About us");//Test the default text for compliance

       //Test whether the length function of qtextbrowser changes when the button is pressed
       QSize oldLength=login.ui->textBrowser_team_intro->size();
       QTest::mouseClick(login.ui->pushButton_team_intro,Qt::LeftButton);
       QSize newLength=login.ui->textBrowser_team_intro->size();
       QVERIFY((newLength.width()-oldLength.width())>0);
       //It should get longer

}
 void TestController::test_Control_volume()
 {
     //Test whether the selection box is valid Whether the sound state has changed
    QVERIFY(dialog.ui->checkBox->isChecked()==0);
    QTest::mouseClick(dialog.ui->checkBox,Qt::LeftButton);
    QVERIFY(dialog.ui->checkBox->isChecked()==1);
 }
 void TestController::test_Control_brightness()
 {
     //Test whether the selection box is valid Does the light state change
    QVERIFY(dialog.ui->checkBox_2->isChecked()==0);
    QTest::mouseClick(dialog.ui->checkBox_2,Qt::LeftButton);
    QVERIFY(dialog.ui->checkBox_2->isChecked()==1);
 }
 void TestController::test_Control_Mouse()
 {
     //Test whether the selection box is valid Whether the mouse state has changed
    QVERIFY(dialog.ui->checkBox_3->isChecked()==0);
    QTest::mouseClick(dialog.ui->checkBox_3,Qt::LeftButton);
    QVERIFY(dialog.ui->checkBox_3->isChecked()==1);
 }
 void TestController::test_Control_switching()
 {
     //Test whether the selection box is valid Has the status changed
    QVERIFY(dialog.ui->checkBox_4->isChecked()==0);
    QTest::mouseClick(dialog.ui->checkBox_4,Qt::LeftButton);
    QVERIFY(dialog.ui->checkBox_4->isChecked()==1);
 }


 void TestController::test_Control_pause()
 {
     //Test whether the selection box is valid Has the status changed
    QVERIFY(dialog.ui->checkBox_5->isChecked()==0);
    QTest::mouseClick(dialog.ui->checkBox_5,Qt::LeftButton);
    QVERIFY(dialog.ui->checkBox_5->isChecked()==1);
 }
 //test_Control_feed
 void TestController::test_Control_feed()
 {
    QVERIFY(dialog.ui->tableWidget->rowCount()==0);//The number of rows should be 0
    QTest::mouseClick(dialog.ui->unprocessed_feed,Qt::LeftButton);
    QVERIFY(dialog.ui->tableWidget->rowCount()==1);//The number of rows should be 1
 }
 void TestController::test_Control_Mask()
 {
     QVERIFY(dialog.ui->tableWidget->rowCount()==1);//The number of rows should be 1
     QTest::mouseClick(dialog.ui->skin_mask,Qt::LeftButton);
     QVERIFY(dialog.ui->tableWidget->rowCount()==2);//The number of rows should be 2
     dialog.ui->tableWidget->clear();//Convenient for other tests（clear）
 }
 void TestController::test_Control_Detector()
 {
     QVERIFY(dialog.ui->tableWidget->rowCount()==2);//The number of rows should be 2
     QTest::mouseClick(dialog.ui->detector,Qt::LeftButton);
     QVERIFY(dialog.ui->tableWidget->rowCount()==3);//The number of rows should be 3
     dialog.ui->tableWidget->clear();//Convenient for other tests（clear）
 }
 void TestController::test_Control_Calibrate()
 {
     QVERIFY(dialog.ui->tableWidget->rowCount()==3);//The number of rows should be 3
     QTest::mouseClick(dialog.ui->calibrate,Qt::LeftButton);
     QVERIFY(dialog.ui->tableWidget->rowCount()==4);//The number of rows should be 4
     dialog.ui->tableWidget->clear();//Convenient for other tests（clear）
 }


QTEST_MAIN(TestController)

#include "tst_testcontroller.moc"
