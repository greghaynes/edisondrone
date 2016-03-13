#include "attitude_updater.h"

#include <functional>
#include <iostream>

using namespace EdisonDrone;

AttitudeUpdater::AttitudeUpdater(unsigned int imu_update_ms,
                                 LSM9DS0Adapter imu)
    : m_9dof_updater(imu_update_ms,
                     std::bind(&AttitudeUpdater::update9Dof, this))
    , m_9dof(std::move(imu))
    , m_estimator()
    , m_gyro_res(4.2760585 / 32768.0)
    , m_accel_res(-2.0 / 32768.0)
    , m_mag_res(2.0 / 32768.0) {
}

AttitudeUpdater::~AttitudeUpdater() {
    if(m_9dof_updater.joinable())
        m_9dof_updater.join();
}

void AttitudeUpdater::start() {
    m_9dof.start();
    m_9dof_updater.start();
}

void AttitudeUpdater::stop() {
    m_9dof_updater.stop();
}

void AttitudeUpdater::update9Dof() {
    int16_t ax, ay, az, gx, gy, gz;
    m_9dof.readGyro();
    m_9dof.readAccel();
    m_9dof.getGyroVals(&gx, &gy, &gz);
    m_9dof.getAccelVals(&ax, &ay, &az);
    m_estimator.update(.01,
                       gx * m_gyro_res,
                       gy * m_gyro_res,
                       gz * m_gyro_res,
                       ax * m_accel_res,
                       ay * m_accel_res,
                       az * m_accel_res,
                       0, 0, 0);
}
