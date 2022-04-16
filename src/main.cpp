 #include "gui/StartScreen.h"
#include "QApplication"
#include "VolumeControl.h"

using namespace std;

int main(int argc,char* argv[] ) {
    QApplication a(argc, argv);
    StartScreen w;
    w.show();

    return a.exec();
}
