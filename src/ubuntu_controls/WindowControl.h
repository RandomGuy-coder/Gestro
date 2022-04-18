#ifndef GESTRO_WINDOW_CONTROL_H
#define GESTRO_WINDOW_CONTROL_H

#include <X11/Xlib.h>  // X11

class WindowControl {
public:
    WindowControl(void);
    Window identifyWindow(Display *display);
    void resize(Display *display, int x, int y);
    void move(Display *display, int x, int y);
    void minimize(Display *display);
    void close(Display *display);
};


#endif //GESTRO_WINDOW_CONTROL_H
