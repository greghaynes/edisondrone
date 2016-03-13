#ifndef IMU_H
#define IMU_H

namespace EdisonDrone {

    class IMU {

        public:
            virtual void start() = 0;
            virtual void readGyro() = 0;
            virtual void readAccel() = 0;
            virtual void getGyroVals(int16_t *x, int16_t *y, int16_t *z) = 0;
            virtual void getAccelVals(int16_t *x, int16_t *y, int16_t *z) = 0;

    };

}

#endif
