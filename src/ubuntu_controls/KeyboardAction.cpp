#include "KeyboardAction.h"

KeyboardAction::KeyboardAction(Display *d){
    display = d;
}
//a key is pressed and then released
void KeyboardAction::pressKey(int keycode){
    KeyboardEvent keyboardEvent;
    keyboardEvent.keyPress(display,keycode);
}