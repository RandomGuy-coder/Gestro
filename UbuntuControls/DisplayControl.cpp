#include "DisplayControl.h"

//Constructor to initialize the class
//The class is called with a pointer to the display
//and an XEvent handler
//this also initializes for window, mouse, volume and keyboard control classes

DisplayControl::DisplayControl(Display* d):mouseAction(d,event),keyboardAction(d),windowAction(d),volumeControl(void){
    display = d;
};
