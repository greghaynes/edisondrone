#include "lsm9ds0_adapter.h"
#include "drone.h"

int main(int argc, char **argv) {
    EdisonDrone::Drone d;
    int ret = d.start();
    return ret;
}
