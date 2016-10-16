#include "gtest/gtest.h"

#include "sensors/lsm9ds0.h"

class LSM9DS0Test : public ::testing::Test {
};

TEST_F(LSM9DS0Test, init) {
    EdisonDrone::LSM9DS0SensorFactory sf(0);
    EdisonDrone::Gyro *g = sf.createGyro();
}
