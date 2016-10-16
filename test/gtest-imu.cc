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
        TestGyro(IMUTest &imu_test)
            : m_imu_test(&imu_test)
            , m_sense_count(0) {}

        virtual void getSenseEvent(EdisonDrone::SensorEvent*) {
            if(m_sense_count == 1)
                m_imu_test->stop();
            else
                m_sense_count = 1;
        }

        IMUTest *m_imu_test;
        int m_sense_count;
};

TEST_F(IMUTest, zero_gyro) {
    TestGyro g(*this);
    EdisonDrone::IMU imu(g, 1*1000);
    this->m_imu = &imu;

    imu.start();
    imu.join();
}
