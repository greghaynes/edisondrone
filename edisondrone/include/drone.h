#ifndef SERVER_H
#define SERVER_H

#include <mutex>

namespace EdisonDrone {

    class Drone {
        public:
            Drone();

            bool isRunning();
            int start();
            void stop();

        private:
            bool m_is_running;
            std::mutex m_start_stop_mutex;
    };

}

#endif
