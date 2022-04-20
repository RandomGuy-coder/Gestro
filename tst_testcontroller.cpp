#include <QtTest>
#include <QCoreApplication>
#include "ui_widget.h"
#include "StartScreen.h"
#include "ControllerScreen.h"
#include "ui_controller_dialog.h"
// add necessary includes here

class TestController : public QObject
{
    Q_OBJECT

public:
    TestController();
    ~TestController();
     StartScreen  login;
     ControllerScreen dialog;
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
       QCOMPARE(login.ui->textBrowser_software_intro->toPlainText(),"Instructions\n");//测试默认文本是否符合

       //测试按钮按下 QTextBrowser 的长度是否函数改变
       QSize oldLength=login.ui->textBrowser_software_intro->size();
       QTest::mouseClick(login.ui->pushButton_software_into,Qt::LeftButton);
       QSize newLength=login.ui->textBrowser_software_intro->size();
       QVERIFY((newLength.width()-oldLength.width())>0);
       //应该会变长

}
void TestController::test_Aboutus()
{

       QCOMPARE(login.ui->textBrowser_team_intro->toPlainText(),"About us");//测试默认文本是否符合

       //测试按钮按下 QTextBrowser 的长度是否函数改变
       QSize oldLength=login.ui->textBrowser_team_intro->size();
       QTest::mouseClick(login.ui->pushButton_team_intro,Qt::LeftButton);
       QSize newLength=login.ui->textBrowser_team_intro->size();
       QVERIFY((newLength.width()-oldLength.width())>0);
       //应该会变长

}
 void TestController::test_Control_volume()
 {
     //测试其选择框是否有效. 声音 状态是否发生改变
    QVERIFY(dialog.ui->checkBox->isChecked()==0);
 }
 void TestController::test_Control_brightness()
 {
     //测试其选择框是否有效. 光亮 状态是否发生改变
    QVERIFY(dialog.ui->checkBox_2->isChecked()==0);
    QTest::mouseClick(dialog.ui->checkBox_2,Qt::LeftButton);
    QVERIFY(dialog.ui->checkBox_2->isChecked()==1);
 }
 void TestController::test_Control_Mouse()
 {
     //测试其选择框是否有效. 鼠标 状态是否发生改变
    QVERIFY(dialog.ui->checkBox_3->isChecked()==0);

 }
 void TestController::test_Control_switching()
 {
     //测试其选择框是否有效. 状态是否发生改变
    QVERIFY(dialog.ui->checkBox_4->isChecked()==0);
    QTest::mouseClick(dialog.ui->checkBox_4,Qt::LeftButton);
    QVERIFY(dialog.ui->checkBox_4->isChecked()==1);
 }


 void TestController::test_Control_pause()
 {
     //测试其选择框是否有效.状态是否发生改变
    QVERIFY(dialog.ui->checkBox_5->isChecked()==0);

 }
 //test_Control_feed
 void TestController::test_Control_feed()
 {
    QVERIFY(dialog.ui->tableWidget->rowCount()==0);//行的数量应该为0
    QTest::mouseClick(dialog.ui->unprocessed_feed,Qt::LeftButton);
    QVERIFY(dialog.ui->tableWidget->rowCount()==1);//行的数量应该为1
 }
 void TestController::test_Control_Mask()
 {
     QVERIFY(dialog.ui->tableWidget->rowCount()==1);//行的数量应该为1
     QTest::mouseClick(dialog.ui->skin_mask,Qt::LeftButton);
     QVERIFY(dialog.ui->tableWidget->rowCount()==2);//行的数量应该为2
     dialog.ui->tableWidget->clear();//方便其他测试
 }
 void TestController::test_Control_Detector()
 {
     QVERIFY(dialog.ui->tableWidget->rowCount()==2);//行的数量应该为2
     QTest::mouseClick(dialog.ui->detector,Qt::LeftButton);
     QVERIFY(dialog.ui->tableWidget->rowCount()==3);//行的数量应该为3
     dialog.ui->tableWidget->clear();//方便其他测试
 }
 void TestController::test_Control_Calibrate()
 {
     QVERIFY(dialog.ui->tableWidget->rowCount()==3);//行的数量应该为3
     QTest::mouseClick(dialog.ui->calibrate,Qt::LeftButton);
     QVERIFY(dialog.ui->tableWidget->rowCount()==4);//行的数量应该为4
     dialog.ui->tableWidget->clear();//方便其他测试
 }


QTEST_MAIN(TestController)

#include "tst_testcontroller.moc"
