#include "VolumeControl.h"
#include "iostream"
#include "stdio.h"
VolumeControl::VolumeControl(void) {

};

//In order to use this function//
//Pass in a long integer value between 0 and 2100
void VolumeControl::increaseVolume()
{
    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);
    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);
    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
    long value;
    snd_mixer_selem_get_playback_volume(elem, SND_MIXER_SCHN_MONO, &value);
    std::cout << value << std::endl;
    snd_mixer_selem_set_playback_volume_all(elem, (value * max / 100) + (max * 0.1));
    snd_mixer_close(handle);
};

void VolumeControl::reduceVolume()
{
    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);
    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);
    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
    long value;
    snd_mixer_selem_get_playback_volume(elem, SND_MIXER_SCHN_MONO, &value);
    snd_mixer_selem_set_playback_volume_all(elem, (value * max / 100) - (max * 0.1));
    snd_mixer_close(handle);
};

int VolumeControl::muteAndUnmute() {
    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);
    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);
    int value;
    snd_mixer_selem_get_playback_switch(elem, SND_MIXER_SCHN_MONO, &value);
    if(value == 1) {
        snd_mixer_selem_set_playback_switch_all(elem, 0);
    } else {
        snd_mixer_selem_set_playback_switch_all(elem, 1);
    }
    snd_mixer_close(handle);
}

int VolumeControl::unmute() {
    snd_mixer_open(&handle, 0);
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);
    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0);
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);
    int value;
    snd_mixer_selem_get_playback_switch(elem, SND_MIXER_SCHN_MONO, &value);
    snd_mixer_selem_set_playback_switch_all(elem, 1);
    snd_mixer_close(handle);
}