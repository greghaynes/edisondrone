#include "imu.h"

#include <functional>

using namespace EdisonDrone;

IMU::IMU(Gyro &gyro, unsigned int gyro_update_usecs,
         const Vector3f &initial_state)
	: m_update_secs(gyro_update_usecs / (1000.0 * 1000.0))
    , m_gyro_listener(gyro,
                      std::bind(&IMU::onGyroUpdate, this,
                                std::placeholders::_1),
                      gyro_update_usecs)
    , m_position(initial_state.x(), initial_state.y(), initial_state.z()) {
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

double IMU::gyroUpdateSecs() const {
    return m_update_secs;
}

const Quaternion &IMU::attitude() const {
	return m_position;
}

void IMU::onGyroUpdate(GyroEvent &ev) {
	Quaternion ev_q(ev.x() * gyroUpdateSecs(),
					ev.y() * gyroUpdateSecs(),
					ev.z() * gyroUpdateSecs());
	m_position.rotate(ev_q);
    m_position.normalize();
}
