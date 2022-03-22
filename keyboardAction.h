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
    int keycode;
public:
    keyboardAction(Display *d, int k);
    void pressKey();
};


#endif //UBUNTU_GESTURECONTROL_KEYBOARDACTION_H
