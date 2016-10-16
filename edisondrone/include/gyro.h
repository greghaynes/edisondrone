#ifndef GYRO_H
#define GYRO_H

#include "sensor.h"
#include "sensor-listener.h"

namespace EdisonDrone {
    class GyroEvent : public SensorEvent {
    };

    class Gyro : public Sensor {
        public:
            void getSenseEvent(SensorEvent *ev) override {};
    };
}

#endif
