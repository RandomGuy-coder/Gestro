//
// Created by terrancewong on 21/03/2022.
//

#include "KeyboardAction.h"

keyboardAction::keyboardAction(Display *d){
    display = d;
}
//a key is pressed and then released
void keyboardAction::pressKey(int keycode){
    keyboard_event keyboardEvent;
    keyboardEvent.keyPress(display,keycode);
}