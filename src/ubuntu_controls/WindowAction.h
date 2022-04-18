#ifndef GESTRO_WINDOWACTION_H
#define GESTRO_WINDOWACTION_H

#include <X11/Xlib.h>  // X11
#include "WindowControl.h"

//Call class to declare a variable
//that can be used to control window action
class WindowAction{
private:
    Display* display;
    Window winFocus;
    int revert;
    WindowControl windowControl;
public:
    WindowAction(Display *d);
    void changeWindowSize(int x, int y);
    void moveWindow(int x, int y);
    void closeWindow();
    void minimizeWindow();
};

#endif //GESTRO_WINDOWACTION_H
