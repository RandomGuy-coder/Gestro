//
// Created by terrancewong on 21/03/2022.
//

#include "window_control.h"

window_control::window_control(void){};

// This function can be used to identify the current window that the pointer is placed over
// The function receives the display as the input and then provides the window as an output
Window window_control::identifyWindow(Display *display)
{
    Window winFocus;
    int revert;
    XGetInputFocus(display, &winFocus, &revert);
    return winFocus;
}

//This function can be used to resize the window
//The function receives the display and the
//height and width as an
void window_control::resize(Display *display, int x, int y)
{
    Window w = identifyWindow(display);
    Window* root;
    Drawable d;
    int* x_loc;
    int* y_loc;
    unsigned int* width;
    unsigned int* height;
    unsigned int* border_width;
    unsigned int* depth;
    XGetGeometry(display, d, &w, x_loc,y_loc,width,height,border_width,depth);
    XResizeWindow(display, w, x, y);

}

void window_control::move(Display *display, int x, int y)
{
    Window w = identifyWindow(display);
    XMoveWindow(display, w, x, y);

}

void window_control::minimize(Display *display)
{
    Window w = identifyWindow(display);
    XIconifyWindow(display, w, DefaultScreen(display));
}

void window_control::close(Display *display)
{
    Window w = identifyWindow(display);
    XDestroyWindow(display, w);
}