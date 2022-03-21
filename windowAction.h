//
// Created by terrancewong on 21/03/2022.
//

#ifndef UBUNTU_GESTURECONTROL_WINDOWACTION_H
#define UBUNTU_GESTURECONTROL_WINDOWACTION_H

#include <X11/Xlib.h>  // X11
#include "window_control.h"

//Call class to declare a variable
//that can be used to control window action
class windowAction{
private:
    Display* display;
    Window winFocus;
    int revert;
    window_control windowControl;
public:
    windowAction(Display *d);
    void changeWindowSize(int x, int y);
    void moveWindow(int x, int y);
    void closeWindow();
    void minimizeWindow();
};

#endif //UBUNTU_GESTURECONTROL_WINDOWACTION_H
