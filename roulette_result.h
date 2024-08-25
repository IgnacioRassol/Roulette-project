#pragma once
#include <vector>


class RouletteResult {
    public:
        RouletteResult(int number);

        int  get_result();
        bool result_is_red();
        bool result_is_black();
        bool result_is_even();
        bool result_is_odd();
        bool result_is_low();
        bool result_is_high();

    private:
        int number;
        bool is_red;
        bool is_black;
        bool is_even;
        bool is_odd;
        bool is_low;
        bool is_high;

        void check_parity();
        void check_high_or_low();
        void check_color();

        static const std::vector<int> red_numbers;
        bool check_is_red(int number);
};

