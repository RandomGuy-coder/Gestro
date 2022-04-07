//
// Created by terrancewong on 21/03/2022.
//

#include "mouseAction.h"

mouseAction::mouseAction(Display* d, XEvent e)
{
    display = d;
    event = e;
}

//this method is used to press down the selected button
void mouseAction::pressButton(int button){
    mouseControl.click(display, button, event);
}

//this method is used to release the selected button
void mouseAction::releaseButton(int button){
    mouseControl.release(display, button, event);
}

//this method moves the mouse pointer from current location by the x and y coordinates specified
void mouseAction::moveMouseTo(int x, int y){
    mouseControl.move(display, x, y);
}

