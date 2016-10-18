#include "gtest/gtest.h"

#include "quaternion.h"

class QuaternionTest : public::testing::Test {
};

TEST_F(QuaternionTest, init_zero_eulers) {
    EdisonDrone::Quaternion q;
    double eulers[3];
    q.toEulers(eulers);

    EXPECT_EQ(eulers[0], 0);
    EXPECT_EQ(eulers[1], 0);
    EXPECT_EQ(eulers[2], 0);
}

TEST_F(QuaternionTest, init_roll_eulers) {
    EdisonDrone::Quaternion q(1, 0, 0);
    double eulers[3];
    q.toEulers(eulers);

    EXPECT_EQ(eulers[0], 1);
    EXPECT_EQ(eulers[1], 0);
    EXPECT_EQ(eulers[2], 0);
}

TEST_F(QuaternionTest, init_pitch_eulers) {
    EdisonDrone::Quaternion q(0, 1, 0);
    double eulers[3];
    q.toEulers(eulers);

    EXPECT_EQ(eulers[0], 0);
    EXPECT_EQ(eulers[1], 1);
    EXPECT_EQ(eulers[2], 0);
}

TEST_F(QuaternionTest, init_yaw_eulers) {
    EdisonDrone::Quaternion q(0, 0, 1);
    double eulers[3];
    q.toEulers(eulers);

    EXPECT_EQ(eulers[0], 0);
    EXPECT_EQ(eulers[1], 0);
    EXPECT_EQ(eulers[2], 1);
}

TEST_F(QuaternionTest, init_yaw_pitch_eulers) {
    EdisonDrone::Quaternion q(0, 1, 1);
    double eulers[3];
    q.toEulers(eulers);

    EXPECT_EQ(eulers[0], 0);
    EXPECT_EQ(eulers[1], 1);
    EXPECT_EQ(eulers[2], 1);
}

TEST_F(QuaternionTest, rotate_roll_eulers) {
    EdisonDrone::Quaternion q(0, 0, 0);
    q.rotate(EdisonDrone::Quaternion(1, 0, 0));
    double eulers[3];
    q.toEulers(eulers);

    EXPECT_EQ(eulers[0], 1);
    EXPECT_EQ(eulers[1], 0);
    EXPECT_EQ(eulers[2], 0);
}

TEST_F(QuaternionTest, rotate_pitch_eulers) {
    EdisonDrone::Quaternion q(0, 0, 0);
    q.rotate(EdisonDrone::Quaternion(0, 1, 0));
    double eulers[3];
    q.toEulers(eulers);

    EXPECT_EQ(eulers[0], 0);
    EXPECT_EQ(eulers[1], 1);
    EXPECT_EQ(eulers[2], 0);
}

TEST_F(QuaternionTest, rotate_yaw_eulers) {
    EdisonDrone::Quaternion q(0, 0, 0);
    q.rotate(EdisonDrone::Quaternion(0, 0, 1));
    double eulers[3];
    q.toEulers(eulers);

    EXPECT_EQ(eulers[0], 0);
    EXPECT_EQ(eulers[1], 0);
    EXPECT_EQ(eulers[2], 1);
}

TEST_F(QuaternionTest, rotate_roll_pitch_unroll_eulers) {
    // This is a pretty straightforward proof that were performing
    // A rotation sequence rather than simple summation:
    // A roll 90deg, pitch 90deg, roll -90deg should result in a yaw 90deg.
    double pi = 3.1415926535897;
    EdisonDrone::Quaternion q(0, 0, 0);
    q.rotate(EdisonDrone::Quaternion(pi * .5, 0, 0));
    q.rotate(EdisonDrone::Quaternion(0, pi * .5, 0));
    q.rotate(EdisonDrone::Quaternion(-pi * .5, 0, 0));
    double eulers[3];
    q.toEulers(eulers);

    EXPECT_GE(eulers[0], -.000001);
    EXPECT_LE(eulers[0], .000001);

    EXPECT_GE(eulers[1], -.000001);
    EXPECT_LE(eulers[1], .000001);

    EXPECT_GE(eulers[2], 1.5707);
    EXPECT_LE(eulers[2], 1.5709);
}
