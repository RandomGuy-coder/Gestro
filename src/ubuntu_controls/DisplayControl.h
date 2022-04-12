#ifndef UBUNTU_GESTURECONTROL_DISPLAYCONTROL_H
#define UBUNTU_GESTURECONTROL_DISPLAYCONTROL_H

#include "WindowAction.h"
#include "KeyboardAction.h"
#include "VolumeControl.h"
#include "MouseAction.h"
#include <X11/Xlib.h>

//this class is used in order to concisely encapsulate
//the classes for keyboard,window, mouse and volume control into a single class
//so that they can be used in a callback function 
//without the user needing to create objects for each of those classes
//any of the methods from the parent classes can be called by simply using dot notation
class DisplayControl: public WindowAction, public KeyboardAction, public MouseAction, public VolumeControl
{
//the member variables for this functiona are the display variable and the event variable    
private:
    //display variable
    Display *display;
    //event variable
    XEvent event;

public:
    //Contructor that initializes all values for the system by taking in a
    DisplayControl(Display* d);
};

#endif //UBUNTU_GESTURECONTROL_DISPLAYCONTROL_H
