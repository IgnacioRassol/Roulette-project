#include <iostream>
#include "player.h"

// Constructor
Player::Player(IBetResultChecker &bet_checker) 
: bet_checker{bet_checker}
, bet_balance{0}
, bet_history{1,2,3,4} {}


// Public Methods
void Player::play(RouletteResult result) {
    int bet_amount = get_bet_amount();
    bool won_bet = bet_checker.won_bet(result);

    update_bet_balance(bet_amount, won_bet);
    update_bet_history(bet_amount, won_bet);
    
}

void Player::print_bet_history() {
    for (int bet : bet_history) {
        std::cout << bet << std::endl;
    }
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
