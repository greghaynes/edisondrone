#ifndef LSM9DS0_ADAPTER_H
#define LSM9DS0_ADAPTER_H

#include "SFE_LSM9DS0.h"

#include "imu.h"

namespace EdisonDrone {

    // This is an adapter for our interface. Although the code is not useful
    // for the drone itself, it enables us to fake the underlying IMU class
    // in testing.
    class LSM9DS0Adapter : public IMU {

        public:
            LSM9DS0Adapter();

            void start() override;
            void readGyro() override;
            void readAccel() override;
            void getGyroVals(double *x, double *y, double *z) override;
            void getAccelVals(double *x, double *y, double *z) override;

        private:
            ::LSM9DS0 m_imu;
            double m_gyro_res;
            double m_accel_res;

    };

}

#endif
