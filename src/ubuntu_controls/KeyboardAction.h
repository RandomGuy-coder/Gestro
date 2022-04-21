#ifndef GESTRO_KEYBOARDACTION_H
#define GESTRO_KEYBOARDACTION_H

#include <X11/Xlib.h>
#include "KeyboardEvent.h"

namespace UbuntuController {
/** @brief A wrapper class for Keyboard Event. */
    class KeyboardAction {
    private:
        /** @brief A pointer to the display.*/
        Display *display;
    public:

        /**
        * Constructor It takes a Display object as an argument and assigns it to
        * the display variable.
        *
        * @param d The display to use.
        */

        KeyboardAction(Display *d);

        /**
        * Wrapper function for pressing Button
        *
        * @param k the keycode of the button to press.
        */
        void pressKey(int k);
    };
}

#endif //GESTRO_KEYBOARDACTION_H
