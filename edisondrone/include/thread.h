#ifndef THREAD_H
#define THREAD_H

#include <functional>
#include <thread>

namespace EdisonDrone {

    class Thread {
        public:
            Thread(std::function<void()> target);
            ~Thread();

            void start();

        private:
            std::thread m_thread;
            std::function<void()> m_target;
    };

}

#endif
