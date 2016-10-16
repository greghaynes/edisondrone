#ifndef LSM9DS0_H
#define LSM9DS0_H

#include "SFE_LSM9DS0.h"

#include "gyro.h"

namespace EdisonDrone {
    class LSM9DS0Gyro : public Gyro {
        public:
            LSM9DS0Gyro(LSM9DS0 &hw);
            void getSenseEvent(SensorEvent *ev);

        private:
            LSM9DS0 *m_hw;
    };

    class LSM9DS0SensorFactory {
        public:
            LSM9DS0SensorFactory(uint8_t gyro_addr,
                                 uint8_t accel_magneto_addr);
            // Takes ownership of LSM9DS0 instance
            //
            // There shouldn't be any reason to use this constructor in
            // practice, but it is useful in testing.
            explicit LSM9DS0SensorFactory(LSM9DS0 *hw);
            ~LSM9DS0SensorFactory();

            LSM9DS0Gyro *createGyro();

        private:
            LSM9DS0 *m_hw;
    };
}

#endif
