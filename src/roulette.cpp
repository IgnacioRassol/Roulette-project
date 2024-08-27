#include "roulette.h"


Roulette::Roulette()
    : mt{std::random_device{}()}
    , dist{0, 36} {}

RouletteResult Roulette::spin() {
    int result = dist(mt);
    return RouletteResult(result);
}
