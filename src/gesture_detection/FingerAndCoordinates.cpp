//
// Created by tushar on 11/04/2022.
//

#include "FingerAndCoordinates.h"

FingerAndCoordinates::FingerAndCoordinates() {
}

FingerAndCoordinates::FingerAndCoordinates(command mycommand, int x, int y) {
    this->count = mycommand;
    this->x = x;
    this->y = y;
}
