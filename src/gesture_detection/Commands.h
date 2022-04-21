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
    /** @brief This is a class that is used to store the enabled commands.*/
    class EnabledCommand {
    public:
        /** @brief flag to check if controlSpacebar is active.*/
        bool controlSpacebar;

        /** @brief flag to check if controlMouse is active.*/
        bool controlMouse;

        /** @brief flag to check if controlMoveWindow is active.*/
        bool controlMoveWindow;

        /** @brief flag to check if controlVolume is active.*/
        bool controlVolume;

        /** @brief flag to check if controlMinimizeWindow is active.*/
        bool controlMinimizeWindow;

        /** Constructor */
        EnabledCommand(void);
    };
}
#endif //GESTRO_COMMANDS_H
