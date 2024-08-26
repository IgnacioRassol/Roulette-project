#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

#include "player.h"

// Constructor
Player::Player(std::shared_ptr<IBetResultChecker> bet_checker, std::string name) 
: bet_checker{bet_checker}
, bet_balance{0}
, bet_history{1,2,3,4}
, name{name} {
}


// Public Methods
void Player::play(RouletteResult result) {
    int bet_amount = get_bet_amount();
    bool won_bet = bet_checker->won_bet(result);

    update_bet_balance(bet_amount, won_bet);
    update_bet_history(bet_amount, won_bet);
    
}

void Player::print_bet_history() {
    for (int bet : bet_history) {
        std::cout << bet << std::endl;
    }
}

int Player::get_bet_balance() {
    return bet_balance;
}

void Player::init_log() {
    std::string filename = name + ".csv";
    std::ofstream outf{ filename };

    if (!outf) {
        throw std::runtime_error("Failed to init log file");
    }

    outf << "Roulette Result, Balance, Bet History" << std::endl;
}

void Player::update_log(int result) {
    std::string filename = name + ".csv";
    std::ofstream outf{ filename, std::ios::app };

    if (!outf) {
        throw std::runtime_error("Failed to update log file");
    }

    outf << result << ", " << bet_balance << ", ";
    for (int bet : bet_history) {
        outf << bet << " ";
    }

    outf << std::endl;
}

// Private Methods
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
    if (bet_amount >= 5 && bet_amount <= 4000) {
        return bet_amount;
    };

    reset_bet_history();
    return bet_history.front() + bet_history.back();
}


void Player::update_bet_balance(int amount, bool won_bet) {
    if (won_bet) {
        bet_balance += amount;
        return;
    };
    
    bet_balance -= amount;
}


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
    // TODO check this
    bet_history = {1,2,3,4};
}
