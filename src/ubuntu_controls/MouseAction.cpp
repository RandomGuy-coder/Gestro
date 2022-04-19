#include "MouseAction.h"

MouseAction::MouseAction(Display* d, XEvent e)
{
    display = d;
    event = e;
}

void MouseAction::pressButton(int button){
    mouseControl.click(display, button, event);
}

void MouseAction::releaseButton(int button){
    mouseControl.release(display, button, event);
}

void MouseAction::moveMouseTo(int x, int y){
    mouseControl.move_to(display, x, y);
}

