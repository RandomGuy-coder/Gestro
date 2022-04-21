#ifndef GESTRO_WINDOWACTION_H
#define GESTRO_WINDOWACTION_H

#include <X11/Xlib.h>  // X11
#include "WindowControl.h"

namespace UbuntuController {
/** @brief Contains functions that accessed by DisplayControl to access the WindowControl. */
    class WindowAction {
    private:

        /** @brief A pointer to the display. */
        Display *display;

        /** @brief A variable that is used to store the window that is currently in focus. */
        Window winFocus;

        /** @brief Used to store the value of the revert-to property of the window. */
        int revert;

        /** @brief Creating an instance of the WindowControl class. */
        WindowControl windowControl;

    public:

        /** constructor.*/
        WindowAction(Display *d);

        /**
        * Call WindowControl to change the size of the window (currently in development)
        *
        * @param x the x coordinate of the window
        * @param y The y coordinate of the window.
        */
        void changeWindowSize(int x, int y);

        /**
        * Call WindowControl to move the window to the specified coordinates.
        *
        * @param x The x coordinate of the window.
        * @param y The y coordinate of the window.
        */
        void moveWindow(int x, int y);

        /**
        * Call WindowControl to close the window (currently in development).
        */
        void closeWindow();

        /**
        * Call WindowControl to minimize the window.
        */
        void minimizeWindow();
    };
}

#endif //GESTRO_WINDOWACTION_H
