#include "imu.h"

#include <functional>

using namespace EdisonDrone;

IMU::IMU(Gyro &gyro, unsigned int gyro_update_usecs)
	: m_update_secs(gyro_update_usecs / (1000.0 * 1000.0))
    , m_gyro_listener(gyro,
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

const Quaternion &IMU::attitude() const {
	return m_position;
}

void IMU::onGyroUpdate(GyroEvent &ev) {
	Quaternion ev_q(ev.x * m_update_secs,
					ev.y * m_update_secs,
					ev.z * m_update_secs);
	m_position.rotate(ev_q);
}
