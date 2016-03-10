#include "server.h"

int main(int argc, char **argv) {
    EdisonDrone::Server s(105);
    return s.start();
}
