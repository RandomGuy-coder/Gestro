#ifndef GESTRO_KEYBOARD_EVENT_H
#define GESTRO_KEYBOARD_EVENT_H

#include <X11/Xlib.h>  // X11
#include <X11/keysymdef.h>

class KeyboardEvent {
public:
    KeyboardEvent(void);
    XKeyEvent createKeyEvent(Display *display, Window &win,
                             Window &winRoot, bool press,
                             int keycode, int modifiers);
    void keyPress(Display *display, int keycode);
};


#endif //GESTRO_KEYBOARD_EVENT_H
