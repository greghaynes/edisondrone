#pragma once

#include "gyro.h"
#include "quaternion.h"
#include "sensor-listener.h"
#include "vector3f.h"

#define PI 3.1415926535897

namespace EdisonDrone {

    class IMU {

        public:
            IMU(Gyro &gyro, unsigned int gyro_update_usecs,
                const Vector3f &initial_state=Vector3f(PI/2.0, 0, 0));

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
