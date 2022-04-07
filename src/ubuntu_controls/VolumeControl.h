#ifndef UBUNTU_GESTURECONTROL_VOLUMECONTROL_H
#define UBUNTU_GESTURECONTROL_VOLUMECONTROL_H

#include <alsa/asoundlib.h>

class VolumeControl {
public:
    VolumeControl(void);
    void SetMasterVolume(long volume);
};


#endif //UBUNTU_GESTURECONTROL_VOLUMECONTROL_H
