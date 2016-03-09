#include "attitude_updater.h"

using namespace EdisonDrone;

AttitudeUpdater::AttitudeUpdater()
    : Thread(std::bind(&AttitudeUpdater::run, this)) {
}

void AttitudeUpdater::run() {
}
