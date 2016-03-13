#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include "attitude_estimator.h"
#include "wave_generator.h"

int main(int argc, char **argv) {
    stateestimation::AttitudeEstimator estimator;

    SinWaveGenerator gyro_gen;
    SinWaveGenerator accel_gen;

    double g_x = 0;
    double g_y = 0;
    double g_z = 0;
    double a_x = 0;
    double a_y = 0;
    double a_z = 0;
    double yaw, pitch, roll;

    std::cout << "# time,g_x,g_y,g_z,a_x,a_y,a_z" << std::endl;
    std::cout << std::setprecision(5) << std::fixed;

    for(int i=0;i < 2000;++i) {
        g_x = gyro_gen();
        estimator.update(.01, g_x, g_y, g_z, a_x, a_y, a_z, 0, 0, 0);

        roll = estimator.eulerRoll();
        pitch = estimator.eulerPitch();
        yaw = estimator.eulerYaw();

        std::cout << i*.01 << "," << g_x << "," << g_y << "," << g_z
                  << "," << a_x << "," << a_y << "," << a_z
                  << "," << roll << "," << pitch << "," << yaw << std::endl;
    }
}
