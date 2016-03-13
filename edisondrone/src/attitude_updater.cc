#include "attitude_updater.h"

#include <cstdint>
#include <functional>
#include <iostream>

using namespace EdisonDrone;

AttitudeUpdater::AttitudeUpdater(unsigned int imu_update_ms,
                                 IMU &imu)
    : m_9dof_updater(imu_update_ms,
                     std::bind(&AttitudeUpdater::update9Dof, this))
    , m_9dof(&imu)
    , m_estimator() {
}

AttitudeUpdater::~AttitudeUpdater() {
    if(m_9dof_updater.joinable())
        m_9dof_updater.join();
}

void AttitudeUpdater::start() {
    m_9dof->start();
    m_9dof_updater.start();
}

void AttitudeUpdater::stop() {
    m_9dof_updater.stop();
}

void AttitudeUpdater::update9Dof() {
    double ax, ay, az, gx, gy, gz;
    m_9dof->readGyro();
    m_9dof->readAccel();
    m_9dof->getGyroVals(&gx, &gy, &gz);
    m_9dof->getAccelVals(&ax, &ay, &az);
    m_estimator.update(.01, gx, gy, gz, ax, ay, az, 0, 0, 0);
}
