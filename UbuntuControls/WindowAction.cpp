//
// Created by terrancewong on 21/03/2022.
//

#include "WindowAction.h"

windowAction::windowAction(Display *d){
    display = d;
}

//call method with new width and height as arguments
void windowAction::changeWindowSize(int x, int y){
    windowControl.resize(display, x, y);
}

//call method with new x and y position from the top left corner
void windowAction::moveWindow(int x, int y){
    windowControl.move(display, x, y);
}
//close the current window
void windowAction::closeWindow(){
    windowControl.close(display);
}

//make the current window an icon
void windowAction::minimizeWindow(){
    windowControl.minimize(display);
}