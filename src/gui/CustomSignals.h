#ifndef TEST_CUSTOMSIGNALS_H
#define TEST_CUSTOMSIGNALS_H

#include "boost/signals2.hpp"

struct CustomSignals{
    boost::signals2::signal<void(Feed)> imageViewChanged;
    boost::signals2::signal<void()> calibrateBackground;
    boost::signals2::signal<void(int,int,int,int)> calibrateValues;
};
#endif //TEST_CUSTOMSIGNALS_H
