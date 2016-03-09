#include <functional>
#include <thread>

#include "gtest/gtest.h"

#include "thread.h"

class ThreadTest : public ::testing::Test {
    public:
        ThreadTest() :
            m_trigger(false),
            m_thread_id(0) {}

        void start_trigger() {
            m_trigger = true;
            m_thread_id = std::this_thread::get_id();
        }

        bool m_trigger;
        std::thread::id m_thread_id;
};

TEST_F(ThreadTest, start_triggers) {
    EdisonDrone::Thread th(std::bind(&ThreadTest::start_trigger, this));
    th.start();
    th.join();

    // We ran start_trigger
    EXPECT_TRUE(m_trigger);
    // We ran start_trigger from another thread id
    EXPECT_NE(std::this_thread::get_id(), m_thread_id);
}
