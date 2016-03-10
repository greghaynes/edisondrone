#include "server.h"

int main(int argc, char **argv) {
    EdisonDrone::Server s(100);
    return s.start();
}
