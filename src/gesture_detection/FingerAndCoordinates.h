#ifndef GESTRO_FINGERANDCOORDINATES_H
#define GESTRO_FINGERANDCOORDINATES_H
#include "Commands.h"

/** @brief class to store the information detected by the FingerCounter.
 */
class FingerAndCoordinates {
public:
    /** @brief stores the command ENUM */
    int command = 0;
    /** @brief int to store the x coordinate of the highest point*/
    int x;
    /** @brief int to store the y coordinate of the highest point*/
    int y;

    /** Default constructor */
    FingerAndCoordinates();

    /**
    * This function is a constructor for the FingerAndCoordinates class.
    *
    * @param newCommand The command that was detected.
    * @param x The x coordinate of the highest point
    * @param y The y coordinate of the highest point.
    */
    FingerAndCoordinates(Commands, int x = 0, int y = 0);
};


#endif //GESTRO_FINGERANDCOORDINATES_H
