#include <iostream>
#include <stdexcept>

#include "simulation.h"

int main() {
    // We wrap this in a try-catch block in case we fail to write to a file when
    // logging player activity.
    try {
        default_simulation();
    }
    catch (std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }


    return 0;
}
