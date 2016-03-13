#ifndef ATTITUDE_UPDATER_H
#define ATTITUDE_UPDATER_H

#include "attitude_estimator.h"
#include "imu.h"
#include "periodic-thread.h"

namespace EdisonDrone {

    class AttitudeUpdater {
        public:
            AttitudeUpdater(unsigned int imu_update_ms,
                            IMU &imu);
            ~AttitudeUpdater();

            void start();
            void stop();

        private:
            void update9Dof();
            void setGyroRes();

            PeriodicThread m_9dof_updater;
            IMU *m_9dof;
            stateestimation::AttitudeEstimator m_estimator;
    };

}

#endif
