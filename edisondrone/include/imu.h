#ifndef IMU_H
#define IMU_H

#include "gyro.h"
#include "quaternion.h"
#include "sensor-listener.h"

namespace EdisonDrone {

    class IMU {

        public:
            IMU(Gyro &gyro, unsigned int gyro_update_usecs);

            void start();
            void stop();
            void join();

			const Quaternion &attitude() const;

        private:
            void onGyroUpdate(GyroEvent &ev);

			double m_update_secs;
            SensorListener<Gyro, GyroEvent> m_gyro_listener;
			Quaternion m_position;
    };

}

#endif
