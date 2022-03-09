#include <stdio.h>     // printf, fprintf and fflush
#include <string.h>    // memset
#include <unistd.h>    // sleep and usleep
#include <X11/Xlib.h>  // X11
#include <X11/Xutil.h> // XGetPixel and XDestroyImage

//This function can be used to identify the current window that the
//the pointer is placed over
// the function receivws the display as the input
//and then provides the window as an output
Window identifyWindow(Display *display)
{
    Window winFocus;
    int revert;
    XGetInputFocus(display, &winFocus, &revert);
    return winFocus;
}

//This function can be used to resize the window
//The function receives the display and the 
//height and width as an 
void resize(Display *display, int x, int y)
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

void move(Display *display, int x, int y)
{
    Window w = identifyWindow(display);
    XMoveWindow(display, w, x, y);

}

void minimize(Display *display)
{
    Window w = identifyWindow(display);
    XIconifyWindow(display, w, DefaultScreen(display));
}

void close(Display *display)
{
    Window w = identifyWindow(display);
    XDestroyWindow(display, w);
}