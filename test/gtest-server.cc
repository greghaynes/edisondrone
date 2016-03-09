#include "gtest/gtest.h"

#include "server.h"

class ServerTest : public ::testing::Test {
};

TEST_F(ServerTest, start) {
    EdisonDrone::Server s;
    int ret = s.run();

    EXPECT_EQ(ret, 0);
    EXPECT_TRUE(s.isRunning());
}
