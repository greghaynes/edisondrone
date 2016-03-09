#include "server.h"

int main(int argc, char **argv) {
    EdisonDrone::Server s(10);
    return s.start();
}
