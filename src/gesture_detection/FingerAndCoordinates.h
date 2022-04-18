//
// Created by tushar on 11/04/2022.
//

#ifndef GESTRO_FINGERANDCOORDINATES_H
#define GESTRO_FINGERANDCOORDINATES_H


class FingerAndCoordinates {
public:
    int count = 0;
    int x;
    int y;
    int distance;
    bool click;
    FingerAndCoordinates();
    FingerAndCoordinates(int count, int x = 0, int y = 0, bool click = false, int distance = 0);
};


#endif //GESTRO_FINGERANDCOORDINATES_H
