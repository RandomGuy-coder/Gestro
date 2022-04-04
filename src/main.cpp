 #include "gui/startScreen.h"
#include "QApplication"

using namespace std;

int main(int argc,char* argv[] ) {
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
