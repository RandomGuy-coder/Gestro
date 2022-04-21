#ifndef GESTRO_MOUSEACTION_H
#define GESTRO_MOUSEACTION_H

#include <X11/Xlib.h>  // X11
#include "MouseControl.h"

namespace UbuntuController {
/** @brief A wrapper class for mouse control. */
    class MouseAction {
    private:

        /** @brief A pointer to the display.*/
        Display *display;

        /** @brief A variable that stores the XEvent*/
        XEvent event;

        /** @brief MouseControl object */
        MouseControl mouseControl;

    public:

        /**
        * Constructor takes a Display and an XEvent and stores them in the class
        *
        * @param d The display that the event occurred on.
        * @param e The XEvent used to trigger the mouse action.
        */
        MouseAction(Display *d, XEvent e);

        /**
        * Wrapper function for pressing Button
        *
        * @param button The button to press.
        */
        void pressButton(int button);

        /**
        * Wrapper function for releasing Button
        *
        * @param button The button to release.
        */
        void releaseButton(int button);

        /**
        * Wrapper function for moving the mouse
        *
        * @param x x-coordinate for mouse position.
        * @param y y-coordinate for mouse position.
        */
        void moveMouseTo(int x, int y);
    };
}

#endif //GESTRO_MOUSEACTION_H
