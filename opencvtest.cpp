//
// Created by tushar on 02/02/2022.
//
#include "opencv2/opencv.hpp"
#include "iostream"
#include "stdio.h"
#include "keyboardAction.h"
#include "mouseAction.h"
#include "windowAction.h"
#include "volumeControl.h"

using namespace cv;
using namespace std;

int main(int, char**)
{
    // Testing
    Display *display;
    display = XOpenDisplay(NULL);
    XEvent event;
    bool keyPressed = false;
    bool windowChanged = false;

    // testing for mouseAction
//    mouseAction mouseAction2 = mouseAction(display, 1, event);
//    mouseAction2.moveMouseTo(500, 500);
//    mouseAction2.pressButton();
//    mouseAction2.releaseButton();

    // testing for volumeControl
//    volumeControl volumeControl2 = volumeControl();
//    volumeControl2.SetMasterVolume(20);

    if (display == NULL)
    {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    int s = DefaultScreen(display);



    /* create window */
    Window window = XCreateSimpleWindow(display, RootWindow(display, s), 10, 10, 200, 200, 1,
                                 BlackPixel(display, s), WhitePixel(display, s));

    /* select kind of events we are interested in */
    XSelectInput(display, window, KeyPressMask | KeyReleaseMask );

    /* map (show) the window */
    XMapWindow(display, window);

    /* event loop */
    while (1)
    {
        XNextEvent(display, &event);

        // testing for windowAction
        if (windowChanged == false) {
            windowAction windowAction2 = windowAction(display);
//            windowAction2.moveWindow(50, 50);
//            windowAction2.closeWindow();
//            windowAction2.minimizeWindow();
            windowAction2.changeWindowSize(500, 500); //doesn't work
            windowChanged = true;
        }

        // testing for keyboardAction
//        if (keyPressed == false) {
//            keyboardAction keyboardAction2 = keyboardAction(display, 0x27);
//            keyboardAction2.pressKey();
//            keyPressed = true;
//        }


        /* keyboard events */
        if (event.type == KeyPress)
        {
            printf( "KeyPress: %x\n", event.xkey.keycode );

            /* exit on ESC key press */
            if ( event.xkey.keycode == 0x09 )
                break;
        }
        else if (event.type == KeyRelease)
        {
            printf( "KeyRelease: %x\n", event.xkey.keycode );
        }
    }

    /* close connection to server */
    XCloseDisplay(display);


//    volumeControl volumeControl;
//    volumeControl.SetMasterVolume(80);



//    VideoCapture cap(0);
//
//    if (!cap.isOpened())
//    {
//        cerr << "Cannot open the video camera" << endl;
//        return -1;
//    }
//    cap.set(3, 1280);
//    cap.set(4, 720);
//
//    cout << cap.get(CAP_PROP_FOURCC) << endl;
//
////    double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
////    double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);
////    double fps = cap.get(CAP_PROP_FPS);
////
////    cout << "The resolution of the video is: " << dWidth << " x " << dHeight << endl;
////    cout << "Frame rate is: " << fps << endl;
//
//    string window_name = "My Camera Feed";
//    namedWindow(window_name); //create a window called "My Camera Feed"
//
//    while (true)
//    {
//        Mat frame;
//        bool bSuccess = cap.read(frame); // read a new frame from video
//
//        //Breaking the while loop if the frames cannot be captured
//        if (bSuccess == false)
//        {
//            cout << "Video camera is disconnected" << endl;
//            cin.get(); //Wait for any key press
//            break;
//        }
//
//        //show the frame in the created window
//        imshow(window_name, frame);
//
//        //wait for for 10 ms until any key is pressed.
//        //If the 'Esc' key is pressed, break the while loop.
//        //If the any other key is pressed, continue the loop
//        //If any key is not pressed withing 10 ms, continue the loop
//        if (waitKey(10) == 27)
//        {
//            cout << "Esc key is pressed by user. Stoppig the video" << endl;
//            break;
//        }
//    }

    return 0;
}

