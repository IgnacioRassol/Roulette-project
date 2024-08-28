#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

#include "player.h"

const std::list<int> Player::initial_bet_history = {1, 2, 3, 4};

Player::Player(
    std::shared_ptr<IBetResultChecker> bet_checker,
    std::string name,
    bool should_log,
    int min_bet,
    int max_bet
    )
    : bet_checker{bet_checker}
    , bet_balance{0}
    , bet_history{initial_bet_history}
    , name{name}
    , should_log{should_log}
    , min_bet{min_bet}
    , max_bet{max_bet} {
    if (should_log) {
        init_log();
    }
}


// Public Methods


void Player::play(const RouletteResult& result) {
    // There is no need to simulate the actual bet since player behavior is
    // constant, so we check if the player won or lost based on the result.
    int bet_amount = get_bet_amount();
    bool won_bet = bet_checker->won_bet(result);

    update_bet_balance(bet_amount, won_bet);
    update_bet_history(bet_amount, won_bet);

    if (should_log) {
        update_log(result.get_result(), won_bet);
    }
}

std::string Player::get_name() const {
    return name;
}

std::list<int> Player::get_bet_history() const {
    return bet_history;
}

int Player::get_bet_balance() const {
    return bet_balance;
}

// Private Methods

// get_bet_amount adds the first and last number of the player's bet history,
// as long as it is within the table maximum and minimum bet, and 
// the player history is not empty. As requested by the requirements,
int Player::get_bet_amount() {
    if (bet_history.empty()) {
        reset_bet_history();
    }

    if (bet_history.size() == 1) {
        return check_bet_within_bounds(bet_history.front());
    }


    return check_bet_within_bounds(bet_history.front() + bet_history.back());
}


int Player::check_bet_within_bounds(int bet_amount) {
    if (bet_amount >= min_bet && bet_amount <= max_bet) {
        return bet_amount;
    }

    reset_bet_history();
    return bet_history.front() + bet_history.back();
}


void Player::update_bet_balance(int amount, bool won_bet) {
    if (won_bet) {
        bet_balance += amount;
        return;
    }

    bet_balance -= amount;
}


// As mentioned in the requirements, if a bet is lost, we remove 
// the first and last number from the history. If the bet is won, 
// we add the bet amount to the history.
void Player::update_bet_history(int bet_amount, bool won_bet) {
    if (won_bet) {
        bet_history.push_back(bet_amount);
        return;
    }

    if (bet_history.size() > 0) {
        bet_history.pop_front();
    }

    if (bet_history.size() > 0) {
        bet_history.pop_back();
    }

    return;
}

void Player::reset_bet_history() {
    bet_history.clear();
    bet_history = initial_bet_history;
}

void Player::init_log() {
    std::string filename = name + ".csv";
    std::ofstream outf{ filename };

    if (!outf) {
        throw std::runtime_error("Failed to init log file");
    }

    outf << "Roulette Result, Won, Balance, Bet History" << std::endl;
}

void Player::update_log(int result, bool won_bet) {
    std::string filename = name + ".csv";
    std::ofstream outf{ filename, std::ios::app };

    if (!outf) {
        throw std::runtime_error("Failed to update log file");
    }

    outf << result << ", "
         << (won_bet ? "won" : "lost") << ", "
         << bet_balance << ", ";
    for (int bet : bet_history) {
        outf << bet << " ";
    }

    outf << std::endl;
}
