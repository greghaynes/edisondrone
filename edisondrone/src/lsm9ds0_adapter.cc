#include "lsm9ds0_adapter.h"

using EdisonDrone::LSM9DS0Adapter;

LSM9DS0Adapter::LSM9DS0Adapter()
    : m_imu(0x6B, 0x1D) {
}

void LSM9DS0Adapter::start() {
    m_imu.begin();
}

void LSM9DS0Adapter::readGyro() {
    m_imu.readGyro();
}

void LSM9DS0Adapter::readAccel() {
    m_imu.readAccel();
}

void LSM9DS0Adapter::getGyroVals(int16_t *x, int16_t *y, int16_t *z) {
    *x = m_imu.gx;
    *y = m_imu.gy;
    *z = m_imu.gz;
}

void LSM9DS0Adapter::getAccelVals(int16_t *x, int16_t *y, int16_t *z) {
    *x = m_imu.ax;
    *y = m_imu.ay;
    *z = m_imu.az;
}
