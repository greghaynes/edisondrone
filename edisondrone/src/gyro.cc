#include "gyro.h"

using namespace EdisonDrone;

GyroEvent::GyroEvent()
    : x(0)
    , y(0)
    , z(0) {
}

GyroEvent::GyroEvent(const GyroEvent &other)
    : x(other.x)
    , y(other.y)
    , z(other.z) {
}

GyroEvent::GyroEvent(double x, double y, double z)
    : x(x)
    , y(y)
    , z(z) {
}

void Gyro::getSenseEvent(SensorEvent *ev) {
    GyroEvent *gev = dynamic_cast<GyroEvent*>(ev);
    getGyroEvent(gev);
}
