//
// Created by terrancewong on 21/03/2022.
//

#ifndef UBUNTU_GESTURECONTROL_VOLUMECONTROL_H
#define UBUNTU_GESTURECONTROL_VOLUMECONTROL_H

#include <alsa/asoundlib.h>

class volumeControl {
public:
    volumeControl(void);
    void SetMasterVolume(long volume);
};


#endif //UBUNTU_GESTURECONTROL_VOLUMECONTROL_H
