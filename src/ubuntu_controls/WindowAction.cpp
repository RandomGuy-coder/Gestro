#include "WindowAction.h"

using namespace UbuntuController;

WindowAction::WindowAction(Display *d){
    display = d;
}

void WindowAction::changeWindowSize(int x, int y){
    windowControl.resize(display, x, y);
}

void WindowAction::moveWindow(int x, int y){
    windowControl.move(display, x, y);
}

void WindowAction::closeWindow(){
    windowControl.close(display);
}

void WindowAction::minimizeWindow(){
    windowControl.minimize(display);
}