#include "attitude_updater.h"

#include <functional>

using namespace EdisonDrone;

AttitudeUpdater::AttitudeUpdater(unsigned int gyro_update_ms)
    : m_gyro_updater(gyro_update_ms,
                     std::bind(&AttitudeUpdater::updateGyros, this)) {
}

void AttitudeUpdater::start() {
    m_gyro_updater.start();
}

void AttitudeUpdater::updateGyros() {
}
