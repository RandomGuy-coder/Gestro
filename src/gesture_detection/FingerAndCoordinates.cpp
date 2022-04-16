//
// Created by tushar on 11/04/2022.
//

#include "FingerAndCoordinates.h"

FingerAndCoordinates::FingerAndCoordinates() {
}

FingerAndCoordinates::FingerAndCoordinates(int count, int x, int y, bool click, int distance) {
    this->count = count;
    this->x = x;
    this->y = y;
    this->click = click;
    this->distance = distance;
}
