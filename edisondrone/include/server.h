#ifndef SERVER_H
#define SERVER_H

#include "attitude_updater.h"

namespace EdisonDrone {

    class Server {
        public:
            Server(unsigned int gyro_update_ms);

            bool isRunning();
            int run();

        private:
            AttitudeUpdater m_attitude_updater;
            bool m_is_running;
    };

}

#endif
