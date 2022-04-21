#ifndef GESTRO_VOLUMECONTROL_H
#define GESTRO_VOLUMECONTROL_H

#include <alsa/asoundlib.h>

namespace UbuntuController {
    /** @brief This class uses the ALSA library to send commands to the sound card. */
    class VolumeControl {

    private:
        /** @brief Declaring three variables of type long.*/
        long min, max;

        /** @brief A pointer to a mixer handle.*/
        snd_mixer_t *handle;

        /** @brief A pointer to a mixer handle.*/
        snd_mixer_selem_id_t *sid;

        /** @brief A pointer to a constant character.*/
        const char *card = "default";

        /** @brief A pointer to a constant character.*/
        const char *selem_name = "Master";

    public:
        /** constructor */
        VolumeControl(void);

        /**
        * Increase the master volume by 10%
        */
        void increaseVolume();

        /**
        * Reduce the master volume by 10%
        */
        void reduceVolume();

        /**
        * Mute or unmute by checking the current state.
        */
        void muteAndUnmute();

        /**
         * Umute the system, to be called before increases volume if system is muted.
         */
        void unmute();
    };
}

#endif //GESTRO_VOLUMECONTROL_H
