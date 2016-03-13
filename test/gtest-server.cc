#include "gtest/gtest.h"


#include "attitude_updater.h"
#include "server.h"

class ServerTest : public ::testing::Test {
};

TEST_F(ServerTest, start) {
    EdisonDrone::Server s(10);
    int ret = s.start();

    EXPECT_EQ(ret, 0);
    EXPECT_TRUE(s.isRunning());

    s.stop();
}
