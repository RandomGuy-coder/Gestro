#include "DisplayControl.h"

using namespace Gestro;

DisplayControl::DisplayControl(Display* d):MouseAction(d,event),KeyboardAction(d),WindowAction(d),VolumeControl(){
    display = d;
}

void DisplayControl::doMouseMove(int x,int y){
    this->moveMouseTo(x,y);
};

void DisplayControl::doKeyPress(int x){
    this->pressKey(x);
};

void DisplayControl::doIncreaseVolume(){
    this->increaseVolume();
};

void DisplayControl::doReduceVolume() {
    this->reduceVolume();
}

void DisplayControl::doMuteUnmute(){
    this->muteAndUnmute();
};

void DisplayControl::doUnmute() {
    this->unmute();
}

void DisplayControl::doButtonPress(int x){
    this->pressButton(x);
};

void DisplayControl::doWindowMove(int x,int y){
    this->moveWindow(x,y);
};

void DisplayControl::doWindowMinimize(){
    this->closeWindow();
};