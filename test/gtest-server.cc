#include "gtest/gtest.h"


#include "attitude_updater.h"
#include "imu.h"
#include "server.h"

class FakeIMU : public EdisonDrone::IMU {

    public:
        void start() override {
        }

        void readGyro() override {
        }

        void readAccel() override {
        }

        void getGyroVals(int16_t *x, int16_t *y, int16_t *z) override {
            *x = 0;
        }

        void getAccelVals(int16_t *x, int16_t *y, int16_t *z) override {
        }

};

class ServerTest : public ::testing::Test {
};

TEST_F(ServerTest, start) {
    FakeIMU *imu = new FakeIMU();
    EdisonDrone::Server s(10, *imu);
    int ret = s.start();

    EXPECT_EQ(ret, 0);
    EXPECT_TRUE(s.isRunning());

    s.stop();
    delete imu;
}
