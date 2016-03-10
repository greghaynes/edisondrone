#include "attitude_updater.h"

#include <functional>
#include <iostream>

using namespace EdisonDrone;

AttitudeUpdater::AttitudeUpdater(unsigned int imu_update_ms)
    : m_9dof_updater(imu_update_ms,
                     std::bind(&AttitudeUpdater::update9Dof, this))
    , m_9dof(0x6B, 0x1D) 
    , m_gyro_res(4.2760585 / 32768.0)
    , m_accel_res(2.0 / 32768.0)
    , m_mag_res(2.0 / 32768.0) {
}

AttitudeUpdater::~AttitudeUpdater() {
    if(m_9dof_updater.joinable())
        m_9dof_updater.join();
}

void AttitudeUpdater::start() {
    m_9dof.begin();
    m_9dof_updater.start();
}

void AttitudeUpdater::stop() {
    m_9dof_updater.stop();
}

void AttitudeUpdater::update9Dof() {
    m_9dof.readGyro();
    m_9dof.readAccel();
    m_estimator.update(.01,
                       m_9dof.gx * m_gyro_res,
                       m_9dof.gy * m_gyro_res,
                       m_9dof.gz * m_gyro_res,
                       m_9dof.ax * m_accel_res,
                       m_9dof.ay * m_accel_res,
                       m_9dof.az * m_accel_res,
                       m_9dof.mx * m_mag_res,
                       m_9dof.my * m_mag_res,
                       m_9dof.mz * m_mag_res);
    std::cout << "roll: " << m_estimator.eulerRoll()
              << " pitch: " << m_estimator.eulerPitch()
              << " yaw: " << m_estimator.eulerYaw() << std::endl;
}
