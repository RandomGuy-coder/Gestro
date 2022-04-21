#include "Commands.h"

using namespace GestureDetection;

EnabledCommand::EnabledCommand() {
    controlMouse = false;
    controlMoveWindow = false;
    controlVolume = false;
    controlSpacebar = false;
    controlMinimizeWindow = false;
}
