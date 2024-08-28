#pragma once

#include <string>
#include <list>
#include <memory>

#include "bet_checker.h"
#include "config.h"

// The player class keeps track of how much money the player has lost so far
// (the house always wins, after all). It's also responsible for figuring out
// the amount of the next bet.
// The responsibility of choosing and determining the outcome of the next
// bet is delegated to the bet checker.
// This represents the player's behavior (for example, always betting red).
class Player {
    public:
        Player(
            std::shared_ptr<IBetResultChecker> bet_checker,
            std::string name,
            bool should_log = config::should_log,
            int min_bet = config::bet_lower_bound,
            int max_bet = config::bet_upper_bound);
        ~Player() = default;

        // The play method uses the received roulette result to check if the 
        // player won or lost and updates the player balance and bet history accordingly.
        void play(const RouletteResult& result);

        // Getters
        std::string get_name() const;
        std::list<int> get_bet_history() const;
        int get_bet_balance() const;

    private:
        // The bet checker is responsible for determining if the player has won.
        std::shared_ptr<IBetResultChecker> bet_checker;
        // The player's balance is the amount of money they have lost or won during the simulation.
        int bet_balance;
        // The bet history is used to determine the amount of the next bet according to some rules.
        std::list<int> bet_history;
        // The player name is used to generate the log file name and display
        // the final results.
        std::string name;
        // Flag used to enable player logging.
        bool should_log;
        // The minimum bet allowed at the table.
        int min_bet;
        // The maximum bet allowed at the table.
        int max_bet;

        // Initial bet history used to decide the first bet.
        static const std::list<int> initial_bet_history;


        int get_bet_amount();
        void update_bet_balance(int amount, bool won_bet);
        void update_bet_history(int bet_amount, bool won_bet);
        void reset_bet_history();
        int check_bet_within_bounds(int bet_amount);

        void init_log();
        void update_log(int result, bool won_bet);
};
