#ifndef GESTRO_DISPLAYCONTROLCALLBACK_H
#define GESTRO_DISPLAYCONTROLCALLBACK_H

/** @briefA An interface to use as callback. */
class DisplayControlCallbackInterface
{
public:
    virtual void doMouseMove(int,int) = 0;
    virtual void doKeyPress(int) = 0;
    virtual void doIncreaseVolume() = 0;
    virtual void doReduceVolume() = 0;
    virtual void doMuteUnmute() = 0;
    virtual void doUnmute() = 0;
    virtual void doButtonPress(int) = 0;
    virtual void doWindowMove(int, int) = 0;
    virtual void doWindowMinimize() = 0;
};

#endif
