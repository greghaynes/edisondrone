#include "gtest/gtest.h"

#include "gyro.h"
#include "imu.h"

#define PI 3.1415926535897

class IMUTest : public ::testing::Test {
    public:
        void stop() {
            m_imu->stop();
        }

        EdisonDrone::IMU *m_imu;
};

class TestGyro : public EdisonDrone::Gyro {
    public:
        TestGyro(IMUTest &imu_test,
                 unsigned int sense_counts,
                 const EdisonDrone::GyroEvent &ev)
            : m_imu_test(&imu_test)
            , m_sense_counts(sense_counts)
            , m_ev(ev) {}

        void getGyroEvent(EdisonDrone::GyroEvent *ev) {
            if(m_sense_counts == 0)
                m_imu_test->stop();
            else
                --m_sense_counts;

            ev->setX(m_ev.x());
            ev->setY(m_ev.y());
            ev->setZ(m_ev.z());
        }

        IMUTest *m_imu_test;
        int m_sense_counts;
        EdisonDrone::GyroEvent m_ev;
};

TEST_F(IMUTest, gyro_called) {
    TestGyro g(*this, 2, EdisonDrone::GyroEvent());
    EdisonDrone::IMU imu(g, 1*1000);
    this->m_imu = &imu;

    imu.start();
    imu.join();
}

TEST_F(IMUTest, gyro_no_motion) {
    TestGyro g(*this, 10,
               EdisonDrone::GyroEvent(0.0, 0.0, 0.0));
    EdisonDrone::IMU imu(g, 1*1000);
    this->m_imu = &imu;

    imu.start();
    imu.join();

	double eulers[3];
	imu.attitude().toEulers(eulers);
	EXPECT_LE(eulers[0], (PI / 2.0) + .0001);
	EXPECT_GE(eulers[0], (PI / 2.0) - .0001);
	EXPECT_EQ(eulers[1], 0);
	EXPECT_EQ(eulers[2], 0);
}
