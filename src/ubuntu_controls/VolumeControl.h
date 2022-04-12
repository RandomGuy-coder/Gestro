#ifndef UBUNTU_GESTURECONTROL_VOLUMECONTROL_H
#define UBUNTU_GESTURECONTROL_VOLUMECONTROL_H

#include <alsa/asoundlib.h>

class VolumeControl {

private:
    long min, max, currentVolume;

    snd_mixer_t *handle;
    snd_mixer_selem_id_t  *sid;
    const char *card = "default";
    const char *selem_name = "Master";

public:
    VolumeControl(void);
    void SetMasterVolume(long volume);
    int muteAndUnmute();
};


#endif //UBUNTU_GESTURECONTROL_VOLUMECONTROL_H
