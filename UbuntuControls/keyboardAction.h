//
// Created by terrancewong on 21/03/2022.
//

#ifndef UBUNTU_GESTURECONTROL_KEYBOARDACTION_H
#define UBUNTU_GESTURECONTROL_KEYBOARDACTION_H

#include <X11/Xlib.h>
#include "keyboard_event.h"

//class to hold all available keyboard shortcuts
//Class is declared using the keycode
//as defined by the keysymdef library

class keyboardAction
{
private:
    Display *display;
public:
    keyboardAction(Display *d);
    void pressKey(int k);
};


#endif //UBUNTU_GESTURECONTROL_KEYBOARDACTION_H
