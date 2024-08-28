#include <algorithm>

#include "roulette_result.h"

// Constructor
RouletteResult::RouletteResult(int number)
    : number{number}
    , is_red{false}
    , is_black{false}
    , is_even{false}
    , is_odd{false}
    , is_low{false}
    , is_high{false}
    {
    if (number != 0) {
        check_parity();
        check_high_or_low();
        check_color();
    }
}

// Public methods
int RouletteResult::get_result() {
    return number;
}

bool RouletteResult::result_is_red() {
    return is_red;
}

bool RouletteResult::result_is_black() {
    return is_black;
}

bool RouletteResult::result_is_even() {
    return is_even;
}

bool RouletteResult::result_is_odd() {
    return is_odd;
}

bool RouletteResult::result_is_low() {
    return is_low;
}

bool RouletteResult::result_is_high() {
    return is_high;
}

// Private methods
void RouletteResult::check_parity() {
    is_even = (number % 2 == 0);
    is_odd = !is_even;
}

void RouletteResult::check_high_or_low() {
    is_low = (number <= 18);
    is_high = !is_low;
}

void RouletteResult::check_color() {
    is_red = check_is_red(number);
    is_black = !is_red;
}

bool RouletteResult::check_is_red(int number) {
    return std::find(red_numbers.begin(), red_numbers.end(), number) != red_numbers.end();
}

// Initialize the static member
const std::vector<int> RouletteResult::red_numbers = {
    1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36
};
