#ifndef GESTRO_KEYBOARD_EVENT_H
#define GESTRO_KEYBOARD_EVENT_H

#include <X11/Xlib.h>  // X11
#include <X11/keysymdef.h>

namespace UbuntuController {

    /** @brief Used to send keyboard events */
    class KeyboardEvent {
    public:
        /** Constructor */
        KeyboardEvent(void);

        /**
        * It creates a key event that can be sent to the X server
        *
        * @param display The display that the event is occuring on.
        * @param win The window that the event is occuring on.
        * @param winRoot The root window is the first window that all windows in the display are descended from.
        * @param press whether the key is pressed or released
        * @param keycode The X11 defined code for the key that is simulated.
        * @param modifiers This is a bitmask that specifies the modifier keys that are pressed.
        *
        * @return A XKeyEvent object
        */
        XKeyEvent createKeyEvent(Display *display, Window &win,
                                 Window &winRoot, bool press,
                                 int keycode, int modifiers);

        /**
        * It creates a fake key press event and sends it to the window which currently has the keyboard focus
        *
        * @param display The Display to send the event to.
        * @param keycode The keycode of the key to be pressed.
        */
        void keyPress(Display *display, int keycode);
    };
}

#endif //GESTRO_KEYBOARD_EVENT_H
