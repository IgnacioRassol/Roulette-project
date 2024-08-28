#include "bet_checker.h"

bool AlwaysRedBetResultChecker::won_bet(const RouletteResult& result) const {
    return result.result_is_red();
}

bool AlwaysBlackBetResultChecker::won_bet(const RouletteResult& result) const {
    return result.result_is_black();
}

bool AlwaysEvenBetResultChecker::won_bet(const RouletteResult& result) const {
    return result.result_is_even();
}

bool AlwaysOddBetResultChecker::won_bet(const RouletteResult& result) const {
    return result.result_is_odd();
}

bool AlwaysLowBetResultChecker::won_bet(const RouletteResult& result) const {
    return result.result_is_low();
}

bool AlwaysHighBetResultChecker::won_bet(const RouletteResult& result) const {
    return result.result_is_high();
}
