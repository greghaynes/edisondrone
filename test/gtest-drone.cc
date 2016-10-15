#include "gtest/gtest.h"

#include "drone.h"

class ServerTest : public ::testing::Test {
};

TEST_F(ServerTest, start) {
    EdisonDrone::Drone d;
    int ret = d.start();

    EXPECT_EQ(ret, 0);
    EXPECT_TRUE(d.isRunning());

    d.stop();
}
