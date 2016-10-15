#ifndef PERIODIC_THREAD_H
#define PERIODIC_THREAD_H

#include <ctime>
#include <functional>

#include "thread.h"

namespace EdisonDrone {

    class PeriodicThread : public Thread {
        public:
            PeriodicThread(unsigned int sleep_us,
                           std::function<void()> target);

            void stop();

        private:
            void run();

            unsigned int m_sleep_us;
            struct timespec m_sleep_ts;
            std::function<void()> m_target;
            bool m_stop_running;
    };

}

#endif
