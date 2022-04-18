#ifndef GESTRO_MOUSEACTION_H
#define GESTRO_MOUSEACTION_H

#include <X11/Xlib.h>  // X11
#include "MouseControl.h"

//class that is used to hold methods for mouse actions
//To use, declare an object in the class with a pointer to
//the display and the button integer that we want to use
class MouseAction
{
private:
    Display *display;
    XEvent event;
    MouseControl mouseControl;
public:
    MouseAction(Display* d, XEvent e);
    void pressButton(int button);
    void releaseButton(int button);
    void moveMouseTo(int x, int y);
};


#endif //GESTRO_MOUSEACTION_H
