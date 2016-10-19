#ifndef GYRO_H
#define GYRO_H

#include "sensor.h"
#include "sensor-listener.h"

namespace EdisonDrone {
    class GyroEvent : public SensorEvent {
        public:
            GyroEvent();
            GyroEvent(const GyroEvent &other);
            GyroEvent(double x, double y, double z);
            double x;
            double y;
            double z;
    };

    class Gyro : public Sensor {
        public:
            void getSenseEvent(SensorEvent *ev) override;
            virtual void getGyroEvent(GyroEvent *ev) = 0;
    };
}

#endif
