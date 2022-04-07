//
// Created by terrancewong on 21/03/2022.
//

#ifndef UBUNTU_GESTURECONTROL_MOUSEACTION_H
#define UBUNTU_GESTURECONTROL_MOUSEACTION_H

#include <X11/Xlib.h>  // X11
#include "MouseControl.h"

//class that is used to hold methods for mouse actions
//To use, declare an object in the class with a pointer to
//the display and the button integer that we want to use
class mouseAction
{
private:
    Display *display;
    XEvent event;
    mouse_control mouseControl;
public:
    mouseAction(Display* d, XEvent e);
    void pressButton(int button);
    void releaseButton(int button);
    void moveMouseTo(int x, int y);
};


#endif //UBUNTU_GESTURECONTROL_MOUSEACTION_H
