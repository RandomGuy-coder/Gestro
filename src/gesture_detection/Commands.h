#ifndef GESTRO_COMMANDS_H
#define GESTRO_COMMANDS_H

/** @brief Defining a list of commands that can be used in the program.*/
enum Commands {
    /** Used to indicate that there is no finger detected. */
    NO_FINGER,
    /** Command to move the mouse*/
    MOUSE_MOVE,
    /** Mouse Click Occured*/
    MOUSE_CLICK,
    /** Increase Volume*/
    VOLUME_UP,
    /** Decrease Volume */
    VOLUME_DOWN,
    /** Mute and Unmute the volume */
    MUTE_UNMUTE,
    /** Move the window */
    MOVE_WINDOW,
    /** Minimize the window */
    MINIMIZE_WINDOW,
    /** Press space bar */
    PRESS_SPACE
};
namespace GestureDetection {
    class EnabledCommand {
    public:
        bool controlSpacebar;
        bool controlMouse;
        bool controlMoveWindow;
        bool controlVolume;
        bool controlMinimizeWindow;

        EnabledCommand(void);
    };
}
#endif //GESTRO_COMMANDS_H
