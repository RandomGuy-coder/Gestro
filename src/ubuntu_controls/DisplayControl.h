#ifndef GESTRO_DISPLAYCONTROL_H
#define GESTRO_DISPLAYCONTROL_H

#include "WindowAction.h"
#include "KeyboardAction.h"
#include "VolumeControl.h"
#include "MouseAction.h"
#include "DisplayControlCallbackInterface.h"
#include <X11/Xlib.h>


/** @brief This is a class that is inheriting from the classes WindowAction, KeyboardAction, MouseAction, VolumeControl, and DisplayControlCallbackInterface.
 *
 *
 * This class is used in order to concisely encapsulate the classes
 * for keyboard,window, mouse and volume control into a single class
 * so that they can be used in a callback function without the user
 * needing to create objects for each of those classes any of the
 * methods from the parent classes can be called by simply using dot notation
 * */
class DisplayControl: public WindowAction, public KeyboardAction, public MouseAction, public VolumeControl, public DisplayControlCallbackInterface
{
private:

    /** @brief A pointer to the display variable. */
    Display *display;

    /** @brief A variable that is used to store the event that is being passed to the callback function. */
    XEvent event;

public:

    /** Constructor that takes in a display variable
     *
     * @param d The display to use.
     * */
    DisplayControl(Display* d);

    /** overrides the DisplayControlInterface method and uses MouseAction to moveMouse*/
    void doMouseMove(int,int) override;
    /** overrides the DisplayControlInterface method and uses KeyboardAction to pressKey*/
    void doKeyPress(int) override;
    /** overrides the DisplayControlInterface method and uses VolumeControl to increaseVolume*/
    void doIncreaseVolume() override;
    /** overrides the DisplayControlInterface method and uses VolumeControl to reduceVolume*/
    void doReduceVolume() override;
    /** overrides the DisplayControlInterface method and uses VolumeControl to unmuteVolume*/
    void doUnmute() override;
    /** overrides the DisplayControlInterface method and uses VolumeControl to muteUnmuteVolume*/
    void doMuteUnmute() override;
    /** overrides the DisplayControlInterface method and uses MouseAction to pressButton*/
    void doButtonPress(int) override;
    /** overrides the DisplayControlInterface method and uses WindowAction to moveWindow*/
    void doWindowMove(int, int) override;
    /** overrides the DisplayControlInterface method and uses WindowAction to minimizeWindow*/
    void doWindowMinimize() override;
};

#endif //GESTRO_DISPLAYCONTROL_H
