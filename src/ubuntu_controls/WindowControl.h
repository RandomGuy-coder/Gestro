#ifndef GESTRO_WINDOW_CONTROL_H
#define GESTRO_WINDOW_CONTROL_H

#include <X11/Xlib.h>  // X11

/** @brief Used to send window events */
class WindowControl {
public:
    /**
    * Constructor
    */
    WindowControl(void);

    /**
    * It returns the window that currently has focus
    *
    * @param display The display to use.
    *
    * @return The window that has focus.
    */
    Window identifyWindow(Display *display);

    /**
    * It takes a display and two integers as arguments, and resizes the window to the given dimensions
    *
    * @param display The display to use.
    * @param x The x coordinate of the upper left corner of the window.
    * @param y The y coordinate of the upper-left outside corner of the window.
    */
    void resize(Display *display, int x, int y);

    /**
    * It moves the window to the specified coordinates
    *
    * @param display The display to use.
    * @param x The x coordinate of the window's new position.
    * @param y The y coordinate of the window's new position.
    */
    void move(Display *display, int x, int y);

    /**
    * It minimizes the window
    *
    * @param display The display to use.
    */
    void minimize(Display *display);

    /**
    * It closes the window
    *
    * @param display The display to use.
    */
    void close(Display *display);
};


#endif //GESTRO_WINDOW_CONTROL_H
