//
// Created by tushar on 18/04/22.
//

#ifndef GESTRO_SIGNALSFINGERCOUNTER_H
#define GESTRO_SIGNALSFINGERCOUNTER_H

#include "boost/signals2.hpp"

struct SignalsFingerCounter{
public:
    boost::signals2::signal<void()> imageViewChanged;
};

#endif //GESTRO_SIGNALSFINGERCOUNTER_H
