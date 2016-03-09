#include "server.h"

using namespace EdisonDrone;

Server::Server(unsigned int gyro_update_ms)
    : m_attitude_updater(gyro_update_ms)
    , m_is_running(false) {
}

bool Server::isRunning() {
    return m_is_running;
}

int Server::run() {
    if(isRunning())
        return 1;

    m_attitude_updater.start();
    m_is_running = true;
    return 0;
}
