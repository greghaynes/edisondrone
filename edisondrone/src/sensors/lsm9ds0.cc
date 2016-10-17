#include "sensors/lsm9ds0.h"

using namespace EdisonDrone;

LSM9DS0Gyro::LSM9DS0Gyro(LSM9DS0 &hw)
    : m_hw(&hw) {
}

void LSM9DS0Gyro::getGyroEvent(GyroEvent *ev) {
    // Read the state of the gyro
}

LSM9DS0SensorFactory::LSM9DS0SensorFactory(uint8_t gyro_addr,
                                           uint8_t accel_magneto_addr)
    : m_hw(new LSM9DS0(gyro_addr, accel_magneto_addr)) {
}

LSM9DS0SensorFactory::LSM9DS0SensorFactory(LSM9DS0 *hw)
    : m_hw(hw) {
}

LSM9DS0SensorFactory::~LSM9DS0SensorFactory() {
    if(m_hw != 0)
        delete m_hw;
}

LSM9DS0Gyro *LSM9DS0SensorFactory::createGyro() {
    return new LSM9DS0Gyro(*m_hw);
}
