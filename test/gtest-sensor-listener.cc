#include <functional>

#include "gtest/gtest.h"

#include "sensor.h"
#include "sensor-listener.h"

class TestEvent : public EdisonDrone::SensorEvent {
};

class TestSensor : public EdisonDrone::Sensor {
    public:
        void getSenseEvent(TestEvent *event) const {
        }
};

class SensorListenerTest : public ::testing::Test {

    public:
        void gotSensorUpdate(const TestEvent &ev) {
            m_sl->stop();
        }

        EdisonDrone::SensorListener<TestSensor, TestEvent> *m_sl;
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
