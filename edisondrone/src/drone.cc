#include "drone.h"
#include "sensor-listener.h"

using namespace EdisonDrone;

Drone::Drone()
    : m_is_running(false) {
}

bool Drone::isRunning() {
    return m_is_running;
}

int Drone::start() {
    m_start_stop_mutex.lock();

    if(isRunning()) {
        m_start_stop_mutex.unlock();
        return 1;
    }

    m_is_running = true;

    m_start_stop_mutex.unlock();
    return 0;
}

void Drone::stop() {
    m_start_stop_mutex.lock();

    m_is_running = false;

    m_start_stop_mutex.unlock();
}
