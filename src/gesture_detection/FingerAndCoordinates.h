#ifndef GESTRO_FINGERANDCOORDINATES_H
#define GESTRO_FINGERANDCOORDINATES_H
#include "commands.h"

class FingerAndCoordinates {
public:
    int count = 0;
    int x;
    int y;
    FingerAndCoordinates();
    FingerAndCoordinates(command, int x = 0, int y = 0);
};


#endif //GESTRO_FINGERANDCOORDINATES_H
