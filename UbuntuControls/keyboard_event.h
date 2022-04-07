//
// Created by terrancewong on 21/03/2022.
//

#ifndef UBUNTU_GESTURECONTROL_KEYBOARD_EVENT_H
#define UBUNTU_GESTURECONTROL_KEYBOARD_EVENT_H

#include <X11/Xlib.h>  // X11
#include <X11/keysymdef.h>

class keyboard_event {
public:
    keyboard_event(void);
    XKeyEvent createKeyEvent(Display *display, Window &win,
                             Window &winRoot, bool press,
                             int keycode, int modifiers);
    void keyPress(Display *display, int keycode);
};


#endif //UBUNTU_GESTURECONTROL_KEYBOARD_EVENT_H
