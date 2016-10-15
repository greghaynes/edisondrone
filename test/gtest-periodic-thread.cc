#include <chrono>
#include <functional>

#include "gtest/gtest.h"

#include "periodic-thread.h"

class PeriodicThreadTest : public ::testing::Test {
    public:
        void record_wakeup() {
            m_wakeup_times.push_back(std::chrono::system_clock::now());
            if(m_wakeup_times.size() >= 5)
                m_pt->stop();
        }

        std::vector<std::chrono::system_clock::time_point> m_wakeup_times;
        EdisonDrone::PeriodicThread *m_pt;
};

TEST_F(PeriodicThreadTest, wakeup_interval) {
    EdisonDrone::PeriodicThread pt(
        10*1000, std::bind(&PeriodicThreadTest::record_wakeup, this)
    );
    m_pt = &pt;
    pt.start();
    pt.join();

    EXPECT_GE(m_wakeup_times.size(), 5);
    for(unsigned int i = 0; i < m_wakeup_times.size() - 1;++i) {
        std::chrono::system_clock::time_point cmp = m_wakeup_times[i];
        cmp = std::chrono::time_point_cast<std::chrono::milliseconds>(
            cmp + std::chrono::milliseconds(10));
        std::chrono::system_clock::time_point next =
            std::chrono::time_point_cast<std::chrono::milliseconds>(
                m_wakeup_times[i+1]);
        std::chrono::system_clock::duration diff = next - cmp;

        // Ensure we have less than 1ms jitter
        EXPECT_GE(diff, std::chrono::milliseconds(-1));
        EXPECT_LE(diff, std::chrono::milliseconds(1));
    }
}
