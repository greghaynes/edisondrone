#ifndef SENSOR_H
#define SENSOR_H

namespace EdisonDrone {
    class SensorEvent {
    };

    class Sensor {
        public:
            virtual void getSenseEvent(SensorEvent*) = 0;
    };
}

#endif
