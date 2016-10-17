#ifndef SENSOR_H
#define SENSOR_H

namespace EdisonDrone {
    class SensorEvent {
        public:
            virtual ~SensorEvent() {};
    };

    class Sensor {
        public:
            virtual ~Sensor() {};
            virtual void getSenseEvent(SensorEvent *ev) = 0;
    };
}

#endif
