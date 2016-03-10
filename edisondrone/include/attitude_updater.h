#ifndef ATTITUDE_UPDATER_H
#define ATTITUDE_UPDATER_H

#include "SFE_LSM9DS0.h"

#include "periodic-thread.h"

namespace EdisonDrone {

    class AttitudeUpdater {
        public:
            AttitudeUpdater(unsigned int gyro_update_ms);
            ~AttitudeUpdater();

            void start();
            void stop();

        private:
            void updateGyros();

            PeriodicThread m_gyro_updater;
            LSM9DS0 m_9dof;
    };

}

#endif
