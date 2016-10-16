#ifndef SENSOR_LISTENER_H
#define SENSOR_LISTENER_H

#include <functional>

#include "periodic-thread.h"

namespace EdisonDrone {

    template <class T, class U>
    class SensorListener {
        public:
            SensorListener(const T& sensor,
                           std::function<void(const U&)> target,
                           unsigned int listen_interval_usecs);

            void start();
            void stop();
            void join();

        private:
            void updateSensor();

            const T *m_sensor;
            std::function<void(const U&)> m_target;
            unsigned int m_listen_interval_usecs;
            PeriodicThread m_listener_thread;
    };

    template <class T, class U>
    SensorListener<T, U>::SensorListener(
        const T& sensor,
        std::function<void(const U&)> target,
        unsigned int listen_interval_usecs)
        : m_sensor(&sensor)
        , m_target(target)
        , m_listen_interval_usecs(listen_interval_usecs)
        , m_listener_thread(
            m_listen_interval_usecs,
            std::bind(&SensorListener<T, U>::updateSensor, this))
    {
    }

    template <class T, class U>
    void SensorListener<T, U>::start() {
        m_listener_thread.start();
    }

    template <class T, class U>
    void SensorListener<T, U>::stop() {
        m_listener_thread.stop();
    }

    template <class T, class U>
    void SensorListener<T, U>::join() {
        m_listener_thread.join();
    }

    template <class T, class U>
    void SensorListener<T, U>::updateSensor() {
        U ev;
        m_sensor->getSenseEvent(&ev);
        m_target(ev);
    }
}

#endif
