#ifndef ATTITUDE_UPDATER_H
#define ATTITUDE_UPDATER_H

#include "thread.h"

namespace EdisonDrone {

    class AttitudeUpdater : public Thread {
        public:
            AttitudeUpdater();

            void run();
    };

}

#endif
