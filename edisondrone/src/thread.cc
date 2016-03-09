#include "thread.h"

using namespace EdisonDrone;

Thread::Thread(std::function<void()> target)
    : m_thread() 
    , m_target(target) {
}

Thread::~Thread() {
    if(m_thread.joinable())
        m_thread.join();
}

void Thread::start() {
    m_thread = std::thread(m_target);
}

void Thread::join() {
    m_thread.join();
}

bool Thread::joinable() {
    return m_thread.joinable();
}
