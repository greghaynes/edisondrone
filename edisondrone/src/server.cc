#include "server.h"

using namespace EdisonDrone;

Server::Server()
    : m_attitude_updater() {
}

bool Server::isRunning() {
    return m_is_running;
}

bool Server::run() {
    if(isRunning())
        return false;

    m_attitude_updater.run();

    return true;
}
