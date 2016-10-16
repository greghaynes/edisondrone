#include <functional>

#include "gtest/gtest.h"

#include "sensor.h"
#include "sensor-listener.h"

class TestEvent : public EdisonDrone::SensorEvent {
};

class TestSensor : public EdisonDrone::Sensor {
    public:
        void getSenseEvent(EdisonDrone::SensorEvent *event) {
        }
};

class SensorListenerTest : public ::testing::Test {

    public:
        SensorListenerTest() : m_update_cnt(0) {}
        void gotSensorUpdate(const TestEvent &ev) {
            if(m_update_cnt == 1)
                m_sl->stop();
            else
                m_update_cnt = 1;
        }

        EdisonDrone::SensorListener<TestSensor, TestEvent> *m_sl;
        int m_update_cnt;
};

TEST_F(SensorListenerTest, get_event) {
    TestSensor s;
    EdisonDrone::SensorListener<TestSensor, TestEvent> sl(
        s,
        std::bind(&SensorListenerTest::gotSensorUpdate, this,
                  std::placeholders::_1),
        10*1000);
    m_sl = &sl;
    sl.start();
    sl.join();
}
