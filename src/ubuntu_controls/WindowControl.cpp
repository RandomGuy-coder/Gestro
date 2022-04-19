#include "WindowControl.h"
#include "iostream"

WindowControl::WindowControl(void){};

Window WindowControl::identifyWindow(Display *display)
{
    Window winFocus;
    int revert;
    XGetInputFocus(display, &winFocus, &revert);
    return winFocus;
}

void WindowControl::resize(Display *display, int x, int y)
{
    Window w = identifyWindow(display);
    XWindowAttributes  windowAttributes;
    try {
        if (XGetWindowAttributes(display, w, &windowAttributes) == 0) {
            std::cerr << "Failed to get window dimensions" << std::endl;
        } else {
            XResizeWindow(display, w, x, y);
        }
    } catch (...) {
        std::cerr << "Error occured" << std::endl;
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