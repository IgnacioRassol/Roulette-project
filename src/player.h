#pragma once

#include <string>
#include <list>
#include <memory>

#include "bet_checker.h"
#include "config.h"

class Player {
    public:
        Player(
            std::shared_ptr<IBetResultChecker> bet_checker,
            std::string name,
            bool should_log = config::should_log,
            int min_bet = config::bet_lower_bound,
            int max_bet = config::bet_upper_bound);
        ~Player() = default;

        void play(RouletteResult result);
        std::string get_name() const;
        std::list<int> get_bet_history() const;
        int get_bet_balance() const;

    private:
        std::shared_ptr<IBetResultChecker> bet_checker;
        int bet_balance;
        std::list<int> bet_history;

        std::string name;
        bool should_log;
        int min_bet;
        int max_bet;

        static const std::list<int> initial_bet_history;


        int get_bet_amount();
        void update_bet_balance(int amount, bool won_bet);
        void update_bet_history(int bet_amount, bool won_bet);
        void reset_bet_history();
        int check_bet_within_bounds(int bet_amount);

        void init_log();
        void update_log(int result, bool won_bet);
};
