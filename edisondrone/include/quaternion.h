#ifndef QUATERNION_H
#define QUATERNION_H

namespace EdisonDrone {
    class Quaternion {
        public:
			Quaternion();
			explicit Quaternion(double *array);
            // RPY are defined as Tait Bryan angles
            Quaternion(double roll, double pitch, double yaw);


			void rotate(const Quaternion &other);
			void toArray(double *arr) const;
			// RPY array
			void toEulers(double *arr) const;

        private:
            double m_q[4];
    };
}

#endif
