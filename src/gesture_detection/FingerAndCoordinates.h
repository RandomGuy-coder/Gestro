#ifndef GESTRO_FINGERANDCOORDINATES_H
#define GESTRO_FINGERANDCOORDINATES_H
#include "Commands.h"

class FingerAndCoordinates {
public:
    int command = 0;
    int x;
    int y;
    FingerAndCoordinates();
    FingerAndCoordinates(Commands, int x = 0, int y = 0);
};


#endif //GESTRO_FINGERANDCOORDINATES_H
