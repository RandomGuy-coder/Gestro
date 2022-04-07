//
// Created by terrancewong on 21/03/2022.
//

#include "keyboardAction.h"

keyboardAction::keyboardAction(Display *d, int k){
    display = d;
    keycode = k;
}
//a key is pressed and then released
void keyboardAction::pressKey(){
    keyboard_event keyboardEvent;
    keyboardEvent.keyPress(display,keycode);
}