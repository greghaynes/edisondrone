#include "quaternion.h"

#include <cmath>

using namespace EdisonDrone;

Quaternion::Quaternion() {
    m_q[0] = 0;
    m_q[1] = 0;
    m_q[2] = 0;
    m_q[3] = 0;
}

Quaternion::Quaternion(double *array) {
    m_q[0] = array[0];
    m_q[1] = array[1];
    m_q[2] = array[2];
    m_q[3] = array[3];
}

Quaternion::Quaternion(double roll, double pitch, double yaw) {
	double t0 = std::cos(yaw * 0.5f);
	double t1 = std::sin(yaw * 0.5f);
	double t2 = std::cos(roll * 0.5f);
	double t3 = std::sin(roll * 0.5f);
	double t4 = std::cos(pitch * 0.5f);
	double t5 = std::sin(pitch * 0.5f);

	m_q[0] = t0 * t2 * t4 + t1 * t3 * t5;
	m_q[1] = t0 * t3 * t4 - t1 * t2 * t5;
	m_q[2] = t0 * t2 * t5 + t1 * t3 * t4;
    m_q[3] = t1 * t2 * t4 - t0 * t3 * t5;
}

void Quaternion::rotate(const Quaternion &other) {
    double q2[4];
    double newval[4];
    other.toArray(q2);

    newval[0] = -m_q[1] * q2[1] - m_q[2] * q2[2] - m_q[3] * q2[3] + m_q[0] * q2[0];
    newval[1] =  m_q[1] * q2[0] + m_q[2] * q2[3] - m_q[3] * q2[2] + m_q[0] * q2[1];
    newval[2] = -m_q[1] * q2[3] + m_q[2] * q2[0] + m_q[3] * q2[1] + m_q[0] * q2[2];
    newval[3] =  m_q[1] * q2[2] - m_q[2] * q2[1] + m_q[3] * q2[0] + m_q[0] * q2[3];

    m_q[0] = newval[0];
    m_q[1] = newval[1];
    m_q[2] = newval[2];
    m_q[3] = newval[3];
}

void Quaternion::toArray(double *arr) const {
    arr[0] = m_q[0];
    arr[1] = m_q[1];
    arr[2] = m_q[2];
    arr[3] = m_q[3];
}

void Quaternion::toEulers(double *arr) const {
    double ysqr = m_q[2] * m_q[2];
    double t0 = -2.0f * (ysqr + m_q[3] * m_q[3]) + 1.0f;
    double t1 = +2.0f * (m_q[1] * m_q[2] + m_q[0] * m_q[3]);
    double t2 = -2.0f * (m_q[1] * m_q[3] - m_q[0] * m_q[2]);
    double t3 = +2.0f * (m_q[2] * m_q[3] + m_q[0] * m_q[1]);
    double t4 = -2.0f * (m_q[1] * m_q[1] + ysqr) + 1.0f;

    t2 = t2 > 1.0f ? 1.0f : t2;
    t2 = t2 < -1.0f ? -1.0f : t2;

    arr[0] = std::atan2(t3, t4);
    arr[1] = std::asin(t2);
    arr[2] = std::atan2(t1, t0);
}
