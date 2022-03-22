//
// Created by terrancewong on 21/03/2022.
//

#ifndef UBUNTU_GESTURECONTROL_WINDOW_CONTROL_H
#define UBUNTU_GESTURECONTROL_WINDOW_CONTROL_H

#include <X11/Xlib.h>  // X11

class window_control {
public:
    window_control(void);
    Window identifyWindow(Display *display);
    void resize(Display *display, int x, int y);
    void move(Display *display, int x, int y);
    void minimize(Display *display);
    void close(Display *display);
};


#endif //UBUNTU_GESTURECONTROL_WINDOW_CONTROL_H
