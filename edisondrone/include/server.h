#ifndef SERVER_H
#define SERVER_H

#include <mutex>

#include "attitude_updater.h"
#include "imu.h"

namespace EdisonDrone {

    class Server {
        public:
            Server(unsigned int imu_update_ms,
                   IMU &imu);

            bool isRunning();
            int start();
            void stop();

        private:
            AttitudeUpdater m_attitude_updater;
            bool m_is_running;
            std::mutex m_start_stop_mutex;
    };

}

#endif
