#include "attitude_updater.h"

#include <functional>

using namespace EdisonDrone;

AttitudeUpdater::AttitudeUpdater(unsigned int gyro_update_ms)
    : m_gyro_updater(gyro_update_ms,
                     std::bind(&AttitudeUpdater::updateGyros, this)) {
}

AttitudeUpdater::~AttitudeUpdater() {
    if(m_gyro_updater.joinable())
        m_gyro_updater.join();
}

void AttitudeUpdater::start() {
    m_gyro_updater.start();
}

void AttitudeUpdater::stop() {
    m_gyro_updater.stop();
}

void AttitudeUpdater::updateGyros() {
}
