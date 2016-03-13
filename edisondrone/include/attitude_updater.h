#ifndef ATTITUDE_UPDATER_H
#define ATTITUDE_UPDATER_H

#include "lsm9ds0_adapter.h"

#include "attitude_estimator.h"
#include "periodic-thread.h"

namespace EdisonDrone {

    class AttitudeUpdater {
        public:
            AttitudeUpdater(unsigned int imu_update_ms,
                            LSM9DS0Adapter imu);
            ~AttitudeUpdater();

            void start();
            void stop();

        private:
            void update9Dof();
            void setGyroRes();

            PeriodicThread m_9dof_updater;
            LSM9DS0Adapter m_9dof;
            stateestimation::AttitudeEstimator m_estimator;
            float m_gyro_res; // Radian conversion factor
            float m_accel_res;
            float m_mag_res;
    };

}

#endif
