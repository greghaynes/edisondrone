#ifndef SERVER_H
#define SERVER_H

#include "attitude_updater.h"

namespace EdisonDrone {

    class Server {
        public:
            Server();

            bool isRunning();
            int run();

        private:
            AttitudeUpdater m_attitude_updater;
            bool m_is_running;
    };

}

#endif
