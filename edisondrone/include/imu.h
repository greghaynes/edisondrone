#ifndef IMU_H
#define IMU_H

namespace EdisonDrone {

    class IMU {

        public:
            virtual ~IMU() {}
            virtual void start() = 0;
            virtual void readGyro() = 0;
            virtual void readAccel() = 0;
            virtual void getGyroVals(double *x, double *y, double *z) = 0;
            virtual void getAccelVals(double *x, double *y, double *z) = 0;

    };

}

#endif
