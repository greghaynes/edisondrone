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

        void getGyroVals(double *x, double *y, double *z) override {
            *x = 0;
            *y = 0;
            *z = 0;
        }

        void getAccelVals(double *x, double *y, double *z) override {
            *x = 0;
            *y = 0;
            *z = 0;
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
