#include "KeyboardAction.h"

using namespace UbuntuController;

KeyboardAction::KeyboardAction(Display *d){
    display = d;
}

void KeyboardAction::pressKey(int keycode){
    KeyboardEvent keyboardEvent;
    keyboardEvent.keyPress(display,keycode);
}