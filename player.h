#pragma once

#include <list>
#include <memory>

#include "bet_checker.h"

class Player {
    public:
        // Constructor
        Player(std::unique_ptr<IBetResultChecker> bet_checker);
        ~Player() = default;
        void play(RouletteResult result);
        void print_bet_history();
        int get_bet_balance();


    private:
        std::unique_ptr<IBetResultChecker> bet_checker;
        int bet_balance;
        std::list<int> bet_history;

        int get_bet_amount();
        void update_bet_balance(int amount, bool won_bet);
        void update_bet_history(int bet_amount, bool won_bet);
        void reset_bet_history();
        int check_bet_within_bounds(int bet_amount);
};
