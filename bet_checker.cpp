#include "bet_checker.h"

// AlwaysRedBetResultChecker implementation
bool AlwaysRedBetResultChecker::won_bet(RouletteResult result) const {
    return result.result_is_red();
}

// AlwaysBlackBetResultChecker implementation
bool AlwaysBlackBetResultChecker::won_bet(RouletteResult result) const {
    return result.result_is_black();
}

// AlwaysEvenBetResultChecker implementation
bool AlwaysEvenBetResultChecker::won_bet(RouletteResult result) const {
    return result.result_is_even();
}

// AlwaysOddBetResultChecker implementation
bool AlwaysOddBetResultChecker::won_bet(RouletteResult result) const {
    return result.result_is_odd();
}

// AlwaysLowBetResultChecker implementation
bool AlwaysLowBetResultChecker::won_bet(RouletteResult result) const {
    return result.result_is_low();
}

// AlwaysHighBetResultChecker implementation
bool AlwaysHighBetResultChecker::won_bet(RouletteResult result) const {
    return result.result_is_high();
}
