#include "periodic-thread.h"

#include "thread"

using namespace EdisonDrone;

PeriodicThread::PeriodicThread(unsigned int sleep_us,
                               std::function<void()> target)
    : Thread(std::bind(&PeriodicThread::run, this))
    , m_sleep_us(sleep_us)
    , m_target(target)
    , m_stop_running(false) {
    m_sleep_ts.tv_sec = 0;
    m_sleep_ts.tv_nsec = m_sleep_us*1000;
}

void PeriodicThread::stop() {
    m_stop_running = true;
}

void PeriodicThread::run() {
    while(!m_stop_running) {
        m_target();
        nanosleep(&m_sleep_ts, NULL);
    }
    m_stop_running = false;
}
