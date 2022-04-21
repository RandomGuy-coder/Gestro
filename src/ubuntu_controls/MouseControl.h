#ifndef GESTRO_MOUSE_CONTROL_H
#define GESTRO_MOUSE_CONTROL_H

#include <X11/Xlib.h>  // X11
#include <stdio.h>     // printf, fprintf and fflush
#include <string.h>    // memset

namespace UbuntuController {
    /** @brief Used to send mouse events */
    class MouseControl {
    public:

        /**
        * Constructor.
        */
        MouseControl(void);

        /**
        * It sends a mouse click event to the X server
        *
        * @param display The display to use.
        * @param button The button to click. 1 is left, 2 is middle, 3 is right.
        * @param event The event to be sent.
        */
        void click(Display *display, int button, XEvent event);

        /**
        * It releases the mouse button
        *
        * @param display the display to use
        * @param button The button to press.
        * @param event the event to send
        */
        void release(Display *display, int button, XEvent event);

        /**
        * It returns the current mouse position
        *
        * @param display The display to use.
        * @param x The x coordinate of the mouse pointer.
        * @param y The y coordinate of the mouse pointer.
        */
        void coords(Display *display, int *x, int *y);

        /**
        * It moves the mouse pointer relative to current coordinates (not being used)
        *
        * @param display The display to use.
        * @param x The x coordinate of the mouse pointer.
        * @param y The y coordinate of the mouse pointer.
        */
        void move(Display *display, int x, int y);

        /**
        * It moves the mouse to the absolute coordinates
        *
        * @param display The display to use.
        * @param x The x coordinate of the mouse pointer.
        * @param y The y coordinate of the mouse pointer.
        */
        void move_to(Display *display, int x, int y);
    };
}

#endif //GESTRO_MOUSE_CONTROL_H
