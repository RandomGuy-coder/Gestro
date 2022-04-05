#include "OutputControl.h"



//Constructor to initialize the class
//The class is called with a pointer to the display
//and an XEvent handler
//this also initializes 
DisplayControl::DisplayControl(Display* d, XEvent e):windowAction(d,e),mouseAction(d),keyboardAction(d){
    display = d;
    event = e;
};
