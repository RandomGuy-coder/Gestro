#include "WindowAction.h"

WindowAction::WindowAction(Display *d){
    display = d;
}

//call method with new width and height as arguments
void WindowAction::changeWindowSize(int x, int y){
    windowControl.resize(display, x, y);
}

//call method with new x and y position from the top left corner
void WindowAction::moveWindow(int x, int y){
    windowControl.move(display, x, y);
}
//close the current window
void WindowAction::closeWindow(){
    windowControl.close(display);
}

//make the current window an icon
void WindowAction::minimizeWindow(){
    windowControl.minimize(display);
}