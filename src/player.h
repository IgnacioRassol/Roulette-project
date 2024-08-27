#pragma once

#include <string>
#include <list>
#include <memory>

#include "bet_checker.h"

class Player {
    public:
        Player(std::shared_ptr<IBetResultChecker> bet_checker, std::string name, bool should_log);
        ~Player() = default;

        void play(RouletteResult result);
        void print_bet_history();
        int get_bet_balance();

    private:
        std::shared_ptr<IBetResultChecker> bet_checker;
        int bet_balance;
        std::list<int> bet_history;
        std::string name;
        bool should_log;


        int get_bet_amount();
        void update_bet_balance(int amount, bool won_bet);
        void update_bet_history(int bet_amount, bool won_bet);
        void reset_bet_history();
        int check_bet_within_bounds(int bet_amount);

        void init_log();
        void update_log(int result, bool won_bet);
};
