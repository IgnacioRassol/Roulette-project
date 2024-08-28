#include <iostream>
#include <stdexcept>

#include "simulation.h"

int main() {
    try {
        default_simulation();
    }
    catch (std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (std::invalid_argument& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }


    return 0;
}
