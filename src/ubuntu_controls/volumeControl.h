//
// Created by terrancewong on 21/03/2022.
//

#ifndef UBUNTU_GESTURECONTROL_VOLUMECONTROL_H
#define UBUNTU_GESTURECONTROL_VOLUMECONTROL_H

#include <alsa/asoundlib.h>

class volumeControl {
private:
{
    long min, max;

    snd_mixer_t *handle;
    snd_mixer_selem_id_t *sid;
    const char *card = "default";
    const char *selem_name = "Master";
}
public:
    volumeControl(void);
    void SetMasterVolume(long volume);
};


#endif //UBUNTU_GESTURECONTROL_VOLUMECONTROL_H
