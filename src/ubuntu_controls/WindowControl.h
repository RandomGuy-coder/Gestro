#ifndef UBUNTU_GESTURECONTROL_WINDOW_CONTROL_H
#define UBUNTU_GESTURECONTROL_WINDOW_CONTROL_H

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


#endif //UBUNTU_GESTURECONTROL_WINDOW_CONTROL_H
