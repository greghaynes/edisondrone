#ifndef IMU_H
#define IMU_H

#include "gyro.h"
#include "sensor-listener.h"

namespace EdisonDrone {

    class IMU {

        public:
            IMU(Gyro &gyro, unsigned int gyro_update_usecs);

            void start();
            void stop();
            void join();

            double eulerRoll() const;
            double eulerPitch() const;
            double eulerYaw() const;

        private:
            void onGyroUpdate(GyroEvent &event);

            SensorListener<Gyro, GyroEvent> m_gyro_listener;

    };

}

#endif
