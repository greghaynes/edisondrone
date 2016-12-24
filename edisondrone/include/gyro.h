#ifndef GYRO_H
#define GYRO_H

#include "sensor.h"
#include "vector3f.h"

namespace EdisonDrone {
    class GyroEvent : public Vector3f, public SensorEvent {
        public:
            GyroEvent() {};
            GyroEvent(const GyroEvent &other) : Vector3f(other) {};
            GyroEvent(double x, double y, double z) : Vector3f(x, y, z) {};
    };

    class Gyro : public Sensor {
        public:
            void getSenseEvent(SensorEvent *ev) override;
            virtual void getGyroEvent(GyroEvent *ev) = 0;
    };
}

#endif
