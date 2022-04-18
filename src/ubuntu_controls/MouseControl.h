#ifndef GESTRO_MOUSE_CONTROL_H
#define GESTRO_MOUSE_CONTROL_H

#include <X11/Xlib.h>  // X11
#include <stdio.h>     // printf, fprintf and fflush
#include <string.h>    // memset

class MouseControl {
public:
    MouseControl(void);
    void click(Display *display, int button, XEvent event);
    void release(Display *display, int button, XEvent event);
    void coords(Display *display, int *x, int *y);
    void move (Display *display, int x, int y);
    void move_to (Display *display, int x, int y);
};


#endif //GESTRO_MOUSE_CONTROL_H
