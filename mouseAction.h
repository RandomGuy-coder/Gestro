#include <stdio.h>     // printf, fprintf and fflush
#include <string.h>    // memset
#include <unistd.h>    // sleep and usleep
#include <X11/Xlib.h>  // X11
#include <X11/Xutil.h> // XGetPixel and XDestroyImage
#include "mouse_control.h"


//class that is used to hold methods for mouse actions
//To use, declare an object in the class with a pointer to 
//the display and the button integer that we want to use
class MouseAction
{
private:
    Display *display;
    int button;
    XEvent event;
public:

    MouseAction(Display* d, int b, XEvent e) {
        display = d;
        button = b;
        event = e;
    }
    //this method is used to press down the selected button
    void pressButton(){
        click(display, button, event);
    }
    //this method is used to release the selected button
    void releaseButton(){
        release(display, button, event);
    }
    //tihs method moves the mouse pointer from current location
    //by the x and y coordinates specified
    void moveMouseTo(int x, int y){
        move(display, x, y);
    }
};

