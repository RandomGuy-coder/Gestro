#include "MouseAction.h"

MouseAction::MouseAction(Display* d, XEvent e)
{
    display = d;
    event = e;
}

//this method is used to press down the selected button
void MouseAction::pressButton(int button){
    mouseControl.click(display, button, event);
}

//this method is used to release the selected button
void MouseAction::releaseButton(int button){
    mouseControl.release(display, button, event);
}

//this method moves the mouse pointer from current location by the x and y coordinates specified
void MouseAction::moveMouseTo(int x, int y){
    mouseControl.move_to(display, x, y);
}

