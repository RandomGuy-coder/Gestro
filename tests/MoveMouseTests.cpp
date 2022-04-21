#include <gtest/gtest.h>
#include "MouseAction.h"
#include <X11/Xlib.h>

using namespace UbuntuController;

TEST(MoveMouseTests, movingMouse) {
    Display *display;
    display = XOpenDisplay(NULL);
    XEvent event;
    MouseAction mouse = MouseAction(display,event);
    mouse.moveMouseTo(0,0);
    XEvent testEvent;
    XQueryPointer (display, RootWindow (display, DefaultScreen (display)),
                   &testEvent.xbutton.root, &testEvent.xbutton.window,
                   &testEvent.xbutton.x_root, &testEvent.xbutton.y_root,
                   &testEvent.xbutton.x, &testEvent.xbutton.y,
                   &testEvent.xbutton.state);


    int x1 = testEvent.xbutton.x;
    int y1 = testEvent.xbutton.y;

    mouse.moveMouseTo(500,500);


    XQueryPointer (display, RootWindow (display, DefaultScreen (display)),
                   &testEvent.xbutton.root, &testEvent.xbutton.window,
                   &testEvent.xbutton.x_root, &testEvent.xbutton.y_root,
                   &testEvent.xbutton.x, &testEvent.xbutton.y,
                   &testEvent.xbutton.state);

    int x2 = testEvent.xbutton.x;
    int y2 = testEvent.xbutton.y;

    int xDiff = x2 - x1;
    int yDiff = y2 - y1;

    XCloseDisplay(display);
    EXPECT_EQ(500, xDiff);
    EXPECT_EQ(500, yDiff);
}

