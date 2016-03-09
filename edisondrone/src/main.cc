#include "attitude_updater.h"

void run() {
    EdisonDrone::AttitudeUpdater au;
    au.run();
}

int main(int argc, char **argv) {
    run();
    return 0;
}
