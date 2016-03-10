#include "attitude_updater.h"

#include <functional>
#include <iostream>

using namespace EdisonDrone;

AttitudeUpdater::AttitudeUpdater(unsigned int gyro_update_ms)
    : m_gyro_updater(gyro_update_ms,
                     std::bind(&AttitudeUpdater::updateGyros, this))
    , m_9dof(0x6B, 0x1D) {
}

AttitudeUpdater::~AttitudeUpdater() {
    if(m_gyro_updater.joinable())
        m_gyro_updater.join();
}

void AttitudeUpdater::start() {
    m_9dof.begin();
    m_gyro_updater.start();
}

void AttitudeUpdater::stop() {
    m_gyro_updater.stop();
}

void AttitudeUpdater::updateGyros() {
    m_9dof.readGyro();
    std::cout << "Gyro x: " << m_9dof.gx << std::endl;
}
