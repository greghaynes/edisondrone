#include "imu.h"

#include <functional>

using namespace EdisonDrone;

IMU::IMU(Gyro &gyro, unsigned int gyro_update_usecs)
    : m_gyro_listener(gyro,
                      std::bind(&IMU::onGyroUpdate, this,
                                std::placeholders::_1),
                      gyro_update_usecs) {
}

void IMU::start() {
    m_gyro_listener.start();
}

void IMU::stop() {
    m_gyro_listener.stop();
}

void IMU::join() {
    m_gyro_listener.join();
}

double IMU::eulerRoll() const {
    return 0;
}

double IMU::eulerPitch() const {
    return 0;
}

double IMU::eulerYaw() const {
    return 0;
}

void IMU::onGyroUpdate(GyroEvent &event) {
}
