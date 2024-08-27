#pragma once

#include <random>

#include "roulette_result.h"

class Roulette{
    public:
        Roulette();
        RouletteResult spin();

    private:
        std::mt19937 mt;
        std::uniform_int_distribution<int> dist;
};
