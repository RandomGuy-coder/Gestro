#include "KeyboardAction.h"

KeyboardAction::KeyboardAction(Display *d){
    display = d;
}

void KeyboardAction::pressKey(int keycode){
    KeyboardEvent keyboardEvent;
    keyboardEvent.keyPress(display,keycode);
}