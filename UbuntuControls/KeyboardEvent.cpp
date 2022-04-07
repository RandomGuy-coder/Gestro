#include "KeyboardEvent.h"

keyboard_event::keyboard_event(void){};

// Function to create a keyboard event
//This function is used in order to simulate a key event i.e. the pressing and releasing of a key
XKeyEvent keyboard_event::createKeyEvent(Display *display, Window &win,
                         Window &winRoot, bool press,
                            int keycode, int modifiers)
{
    //declare a key press event
    XKeyEvent event;

    //specify the display for the event
    event.display     = display;
    //specify the window for the event
    event.window      = win;
    //specify the root window for the event which is the first window that all windows in the display are descended from
    event.root        = winRoot;
    //specify whether there is any child window for the event
    event.subwindow   = None;
    //specify when the event is occuring
    event.time        = CurrentTime;
    //specify the location for the event
    event.x           = 1;
    event.y           = 1;
    event.x_root      = 1;
    event.y_root      = 1;
    //specify that the event is occuring on the same screen
    event.same_screen = True;
    //specify the X11 defined code for the key that is simulated
    event.keycode     = XKeysymToKeycode(display, keycode);
    //specify the current state for the specified key
    event.state       = modifiers;
    if(press)
        event.type = KeyPress;
    else
        event.type = KeyRelease;

    return event;
}
void keyboard_event::keyPress(Display *display, int keycode){

// Get the root window for the current display.
    Window winRoot = XDefaultRootWindow(display);

// Find the window which has the current keyboard focus.
    Window winFocus;
    int revert;

    XGetInputFocus(display, &winFocus, &revert);

// Send a fake key press event to the window.
    XKeyEvent event = createKeyEvent(display, winFocus, winRoot, true, keycode, 0);
    XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);

// Send a fake key release event to the window.
    event = createKeyEvent(display, winFocus, winRoot, false, keycode, 0);
    XSendEvent(event.display, event.window, True, KeyPressMask, (XEvent *)&event);

}