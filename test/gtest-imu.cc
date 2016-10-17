#include "gtest/gtest.h"

#include "gyro.h"
#include "imu.h"

class IMUTest : public ::testing::Test {
    public:
        void stop() {
            m_imu->stop();
        }

        EdisonDrone::IMU *m_imu;
};

class TestGyro : public EdisonDrone::Gyro {
    public:
        TestGyro(IMUTest &imu_test, unsigned int sense_counts)
            : m_imu_test(&imu_test)
            , m_sense_counts(sense_counts) {}

        void getGyroEvent(EdisonDrone::GyroEvent *ev) {
            if(m_sense_counts == 0)
                m_imu_test->stop();
            else
                --m_sense_counts;

            ev->x = 0;
            ev->y = 0;
            ev->z = 0;
        }

        IMUTest *m_imu_test;
        int m_sense_counts;
};

TEST_F(IMUTest, gyro_called) {
    TestGyro g(*this, 2);
    EdisonDrone::IMU imu(g, 1*1000);
    this->m_imu = &imu;

    imu.start();
    imu.join();
}

TEST_F(IMUTest, gyro_zero_only) {
    TestGyro g(*this, 10);
    EdisonDrone::IMU imu(g, 1*1000);
    this->m_imu = &imu;

    imu.start();
    imu.join();

    EXPECT_EQ(imu.eulerRoll(), 0);
    EXPECT_EQ(imu.eulerPitch(), 0);
    EXPECT_EQ(imu.eulerYaw(), 0);
}
