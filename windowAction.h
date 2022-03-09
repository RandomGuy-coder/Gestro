#include <stdio.h>     // printf, fprintf and fflush
#include <string.h>    // memset
#include <unistd.h>    // sleep and usleep
#include <X11/Xlib.h>  // X11
#include "window_control.h"

//Call class to declare a variable
//that can be used to control window action
class WindowAction{
private:
    Display* display;
    Window winFocus;
    int revert;

public:
    WindowAction(Display *d){
        display = d;
    }

    //call method with new width
    //and height as arguments
    void changeWindowSize(int x, int y){
        resize(display, x, y);
    }

    //call method with new
    //x and y position for the top right corner
    void moveWindow(int x, int y){
        move(display, x, y);
    }
    //close the current window
    void closeWindow(){
        close(display);
    }

    //make the current window an icon
    void minimizeWindow(){
        minimize(display);
    }

};