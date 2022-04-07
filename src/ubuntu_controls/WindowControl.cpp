#include "WindowControl.h"

WindowControl::WindowControl(void){};

// This function can be used to identify the current window that the pointer is placed over
// The function receives the display as the input and then provides the window as an output
Window WindowControl::identifyWindow(Display *display)
{
    Window winFocus;
    int revert;
    XGetInputFocus(display, &winFocus, &revert);
    return winFocus;
}

//This function can be used to resize the window
//The function receives the display and the
//height and width as an
void WindowControl::resize(Display *display, int x, int y)
{
    Window w = identifyWindow(display);
    Window* root;
    int* x_loc;
    int* y_loc;
    unsigned int* width;
    unsigned int* height;
    unsigned int* border_width;
    unsigned int* depth;
    XGetGeometry(display, w, root, x_loc,y_loc,width,height, border_width, depth);
    XResizeWindow(display, w, x, y);

}

void WindowControl::move(Display *display, int x, int y)
{
    Window w = identifyWindow(display);
    XMoveWindow(display, w, x, y);

}

void WindowControl::minimize(Display *display)
{
    Window w = identifyWindow(display);
    XIconifyWindow(display, w, DefaultScreen(display));
}

void WindowControl::close(Display *display)
{
    Window w = identifyWindow(display);
    XDestroyWindow(display, w);
}