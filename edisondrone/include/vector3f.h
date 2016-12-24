#pragma once

namespace EdisonDrone {
    class Vector3f {
        public:
            Vector3f();
            Vector3f(const Vector3f &other);
            Vector3f(double x, double y, double z);

            double x() const;
            double y() const;
            double z() const;
            void setX(double x);
            void setY(double y);
            void setZ(double z);

        private:
            double m_x;
            double m_y;
            double m_z;
    };
}
