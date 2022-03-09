#include <stdio.h>     // printf, fprintf and fflush
#include <string.h>    // memset
#include <unistd.h>    // sleep and usleep
#include <X11/Xlib.h>  // X11
#include <X11/keysymdef.h>
#include "keyboard_event.h"


//class to hold all available keyboard shortcuts
//Class is declared using the keycode 
//as defined by the keysymdef library

class keyboardAction
{
    private:
        Display *display;
        int keycode;
    public:
        keyboardAction(Display *d, int k){
            display = d;
            keycode = k;
        }
        //a key is pressed and then released
        void pressKey(){
            keyPress(display,keycode);
        }

};