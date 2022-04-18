#include "gui/StartScreen.h"
#include "QApplication"

using namespace std;

int main(int argc,char* argv[] ) {
    QApplication a(argc, argv);
    StartScreen w;
    w.show();

    return a.exec();

}
