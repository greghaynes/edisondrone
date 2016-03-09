#include <thread>

#include "periodic-thread.h"

using namespace EdisonDrone;

PeriodicThread::PeriodicThread(unsigned int sleep_ms,
                               std::function<void()> target)
    : Thread(std::bind(&PeriodicThread::run, this))
    , m_sleep_ms(sleep_ms)
    , m_target(target) {
    m_sleep_ts.tv_sec = 0;
    m_sleep_ts.tv_nsec = m_sleep_ms*1000*1000;
}

void PeriodicThread::stop() {
    m_stop_running = true;
}

void PeriodicThread::run() {
    m_stop_running = false;

    while(!m_stop_running) {
        m_target();
        nanosleep(&m_sleep_ts, NULL);
    }
}
