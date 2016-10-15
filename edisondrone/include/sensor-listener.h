#ifndef SENSOR_LISTENER_H
#define SENSOR_LISTENER_H

#include "periodic-thread.h"

#include <functional>

namespace EdisonDrone {

    template <class T, class U>
    class SensorListener {
        public:
            SensorListener(const T& sensor,
                           std::function<void(const T&, const U&)> target,
                           unsigned int listen_interval_usecs);

            void start();
            void stop();

        private:
            void updateSensor();

            const T *m_sensor;
            std::function<void(const T&, const U&)> m_target;
            unsigned int m_listen_interval_usecs;
            PeriodicThread *m_listener_thread;
    };

    template <class T, class U>
    SensorListener<T, U>::SensorListener(
        const T& sensor,
        std::function<void(const T&, const U&)> target,
        unsigned int listen_interval_usecs)
        : m_sensor(&sensor)
        , m_target(target)
        , m_listen_interval_usecs(listen_interval_usecs)
        , m_listener_thread(0) {
    }

    template <class T, class U>
    void SensorListener<T, U>::start() {
        if(m_listener_thread == 0)
            m_listener_thread = PeriodicThread(
                m_listen_interval_usecs,
                std::bind(&SensorListener<T, U>::updateSensor, this));
    }

    template <class T, class U>
    void SensorListener<T, U>::stop() {
        if(m_listener_thread != 0) {
            m_listener_thread->stop();
            m_listener_thread->join();
        }
    }

    template <class T, class U>
    void SensorListener<T, U>::updateSensor() {
        m_target(m_sensor->getSenseEvent());
    }
}

#endif
