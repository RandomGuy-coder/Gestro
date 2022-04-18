#ifndef GESTRO_VOLUMECONTROL_H
#define GESTRO_VOLUMECONTROL_H

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
    void increaseVolume();
    void reduceVolume();
    int muteAndUnmute();
    int unmute();
};


#endif //GESTRO_VOLUMECONTROL_H
