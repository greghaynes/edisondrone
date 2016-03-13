#include "lsm9ds0_adapter.h"

using EdisonDrone::LSM9DS0Adapter;

LSM9DS0Adapter::LSM9DS0Adapter()
    : m_imu(0x6B, 0x1D)
    , m_gyro_res(4.2760585 / 32768.0)
    , m_accel_res(-2.0 / 32768.0) {
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

void LSM9DS0Adapter::getGyroVals(double *x, double *y, double *z) {
    *x = m_imu.gx * m_gyro_res;
    *y = m_imu.gy * m_gyro_res;
    *z = m_imu.gz * m_gyro_res;
}

void LSM9DS0Adapter::getAccelVals(double *x, double *y, double *z) {
    *x = m_imu.ax * m_accel_res;
    *y = m_imu.ay * m_accel_res;
    *z = m_imu.az * m_accel_res;
}
