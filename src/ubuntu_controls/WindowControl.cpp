#include "WindowControl.h"
#include "iostream"

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
    XWindowAttributes  windowAttributes;
    try {
        if (XGetWindowAttributes(display, w, &windowAttributes) == 0) {
            std::cout << "Failed to get window dimensions";
        } else {
            XResizeWindow(display, w, x, y);
        }
    } catch (...) {
        std::cout << "Error occured";
    }

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