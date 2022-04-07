
#ifndef UBUNTU_GESTURECONTROL_DISPLAYCONTROL_H
#define UBUNTU_GESTURECONTROL_DISPLAYCONTROL_H

#include "windowAction.h"
#include "keyboardAction.h"
#include "volumeControl.h"
#include "mouseAction.h"
#include <X11/Xlib.h>

//this class is used in order to concisely encapsulate
//the classes for keyboard,window, mouse and volume control into a single class
//so that they can be used in a callback function 
//without the user needing to create objects for each of those classes
//any of the methods from the parent classes can be called by simply using dot notation

class DisplayControl: public windowAction, public keyboardAction, public mouseAction, public volumeControl
{
private:
    Display *display;
    XEvent event;

public:
    DisplayControl(Display *d, XEvent e):windowAction(d),mouseAction(d,e),keyboardAction(d){};
}

#endif //UBUNTU_GESTURECONTROL_DISPLAYCONTROL_H
