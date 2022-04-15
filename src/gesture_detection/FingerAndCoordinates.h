//
// Created by tushar on 11/04/2022.
//

#ifndef TEST_FINGERANDCOORDINATES_H
#define TEST_FINGERANDCOORDINATES_H


class FingerAndCoordinates {
public:
    int count = 0;
    int x = 0;
    int y = 0;
    bool click;
    FingerAndCoordinates();
    FingerAndCoordinates(int count, int x, int y, bool moved);
};


#endif //TEST_FINGERANDCOORDINATES_H
