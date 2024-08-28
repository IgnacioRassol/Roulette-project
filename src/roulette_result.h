#pragma once

#include <vector>

// Class that represents a roulette result, with all the information necessary
// to easily check if one of the basic bets
// (i.e. red/black, odd/even, high/low) has won.
class RouletteResult {
    public:
        explicit RouletteResult(int number);

        int  get_result() const;
        bool result_is_red() const;
        bool result_is_black() const;
        bool result_is_even() const;
        bool result_is_odd() const;
        bool result_is_low() const;
        bool result_is_high() const;

    private:
        int number;
        bool is_red;
        bool is_black;
        bool is_even;
        bool is_odd;
        bool is_low;
        bool is_high;
        static const std::vector<int> red_numbers;

        void check_parity();
        void check_high_or_low();
        void check_color();

        bool check_is_red(int number);
};

