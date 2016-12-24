#include "vector3f.h"

using namespace EdisonDrone;

Vector3f::Vector3f()
 : m_x(0), m_y(0), m_z(0) {
}

Vector3f::Vector3f(const Vector3f &other)
 : m_x(other.x()), m_y(other.y()), m_z(other.z()) {
}

Vector3f::Vector3f(double x, double y, double z)
 : m_x(x), m_y(y), m_z(z) {
}

double Vector3f::x() const {
    return m_x;
}

double Vector3f::y() const {
    return m_y;
}

double Vector3f::z() const {
    return m_z;
}

void Vector3f::setX(double x) {
    m_x = x;
}

void Vector3f::setY(double y) {
    m_y = y;
}

void Vector3f::setZ(double z) {
    m_z = z;
}
