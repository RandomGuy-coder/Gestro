//
// Created by terrancewong on 21/03/2022.
//

#include "mouse_control.h"

mouse_control::mouse_control(void){};

// Simulate mouse click
void mouse_control::click (Display *display, int button, XEvent event)
{
    // Setting up the event
    memset (&event, 0, sizeof (event));
    event.xbutton.button = button;
    event.xbutton.same_screen = True;
    event.xbutton.subwindow = DefaultRootWindow (display);
    while (event.xbutton.subwindow)
    {
        event.xbutton.window = event.xbutton.subwindow;
        XQueryPointer (display, event.xbutton.window,
                       &event.xbutton.root, &event.xbutton.subwindow,
                       &event.xbutton.x_root, &event.xbutton.y_root,
                       &event.xbutton.x, &event.xbutton.y,
                       &event.xbutton.state);
    }
    // Press
    event.type = ButtonPress;
    if (XSendEvent (display, PointerWindow, True, ButtonPressMask, &event) == 0)
        fprintf (stderr, "Error to send the event!\n");
    XFlush (display);
}

//release the selected button
void mouse_control::release(Display *display, int button, XEvent event) {
    memset (&event, 0, sizeof (event));
    event.xbutton.button = button;
    event.xbutton.same_screen = True;
    event.xbutton.subwindow = DefaultRootWindow (display);
    while (event.xbutton.subwindow)
    {
        event.xbutton.window = event.xbutton.subwindow;
        XQueryPointer (display, event.xbutton.window,
                       &event.xbutton.root, &event.xbutton.subwindow,
                       &event.xbutton.x_root, &event.xbutton.y_root,
                       &event.xbutton.x, &event.xbutton.y,
                       &event.xbutton.state);
    }
    event.type = ButtonRelease;
    if (XSendEvent (display, PointerWindow, True, ButtonReleaseMask, &event) == 0)
        fprintf (stderr, "Error to send the event!\n");
    XFlush (display);
}
// Get mouse coordinates
void mouse_control::coords(Display *display, int *x, int *y)
{
    XEvent event;
    XQueryPointer (display, DefaultRootWindow (display),
                   &event.xbutton.root, &event.xbutton.window,
                   &event.xbutton.x_root, &event.xbutton.y_root,
                   &event.xbutton.x, &event.xbutton.y,
                   &event.xbutton.state);
    *x = event.xbutton.x;
    *y = event.xbutton.y;
}

// Move mouse pointer (relative)
void mouse_control::move (Display *display, int x, int y)
{
    XWarpPointer (display, None, None, 0,0,0,0, x, y);
    XFlush (display);
}

// Move mouse pointer (absolute)
void mouse_control::move_to (Display *display, int x, int y)
{
    int cur_x, cur_y;
    coords (display, &cur_x, &cur_y);
    XWarpPointer (display, None, None, 0,0,0,0, -cur_x, -cur_y);
    XWarpPointer (display, None, None, 0,0,0,0, x, y);
}