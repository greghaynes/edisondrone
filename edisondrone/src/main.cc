#include "lsm9ds0_adapter.h"
#include "server.h"

int main(int argc, char **argv) {
    EdisonDrone::LSM9DS0Adapter *imu = new EdisonDrone::LSM9DS0Adapter();
    EdisonDrone::Server s(100, *imu);
    int ret = s.start();
    delete imu;
    return ret;
}
