#include "gyro.h"

using namespace EdisonDrone;

void Gyro::getSenseEvent(SensorEvent *ev) {
    GyroEvent *gev = dynamic_cast<GyroEvent*>(ev);
    getGyroEvent(gev);
}
