#include "bet_checker.h"

bool AlwaysRedBetResultChecker(const RouletteResult& result) {
    return result.result_is_red();
}

bool AlwaysBlackBetResultChecker(const RouletteResult& result) {
    return result.result_is_black();
}

bool AlwaysEvenBetResultChecker(const RouletteResult& result) {
    return result.result_is_even();
}

bool AlwaysOddBetResultChecker(const RouletteResult& result) {
    return result.result_is_odd();
}

bool AlwaysLowBetResultChecker(const RouletteResult& result) {
    return result.result_is_low();
}

bool AlwaysHighBetResultChecker(const RouletteResult& result) {
    return result.result_is_high();
}
