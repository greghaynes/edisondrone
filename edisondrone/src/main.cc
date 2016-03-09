#include "server.h"

int main(int argc, char **argv) {
    EdisonDrone::Server s;
    return s.run();
}
