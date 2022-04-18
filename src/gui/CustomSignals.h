#ifndef GESTRO_CUSTOMSIGNALS_H
#define GESTRO_CUSTOMSIGNALS_H

#include "boost/signals2.hpp"

struct CustomSignals{
    boost::signals2::signal<void(Feed)> imageViewChanged;
    boost::signals2::signal<void()> calibrateBackground;
    boost::signals2::signal<void(int,int,int,int)> calibrateValues;
};
#endif //GESTRO_CUSTOMSIGNALS_H
