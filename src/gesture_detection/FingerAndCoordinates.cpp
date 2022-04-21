#include "FingerAndCoordinates.h"

using namespace GestureDetection;

FingerAndCoordinates::FingerAndCoordinates() {
}

FingerAndCoordinates::FingerAndCoordinates(Commands newCommand, int x, int y) {
    this->command = newCommand;
    this->x = x;
    this->y = y;
}
