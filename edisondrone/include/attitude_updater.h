#ifndef ATTITUDE_UPDATER_H
#define ATTITUDE_UPDATER_H

#include "periodic-thread.h"

namespace EdisonDrone {

    class AttitudeUpdater {
        public:
            AttitudeUpdater(unsigned int gyro_update_ms);

            void start();

        private:
            void updateGyros();

            PeriodicThread m_gyro_updater;
    };

}

#endif
