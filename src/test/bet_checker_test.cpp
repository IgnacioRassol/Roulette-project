#include "bet_checker.h"
#include "catch_amalgamated.hpp"

TEST_CASE("AlwaysRedBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    AlwaysRedBetResultChecker red_checker;
    RouletteResult red_result{1};
    RouletteResult black_result{2};
    RouletteResult zero_result{0};

    REQUIRE(red_checker.won_bet(red_result));
    REQUIRE_FALSE(red_checker.won_bet(black_result));
    REQUIRE_FALSE(red_checker.won_bet(zero_result));
}

TEST_CASE("AlwaysBlackBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    AlwaysBlackBetResultChecker black_checker;
    RouletteResult red_result{1};
    RouletteResult black_result{2};
    RouletteResult zero_result{0};


    REQUIRE_FALSE(black_checker.won_bet(red_result));
    REQUIRE(black_checker.won_bet(black_result));
    REQUIRE_FALSE(black_checker.won_bet(zero_result));
}


TEST_CASE("AlwaysEvenBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    AlwaysEvenBetResultChecker even_checker;
    RouletteResult even_result{2};
    RouletteResult odd_result{3};\
    RouletteResult zero_result{0};


    REQUIRE(even_checker.won_bet(even_result));
    REQUIRE_FALSE(even_checker.won_bet(odd_result));
    REQUIRE_FALSE(even_checker.won_bet(zero_result));
}

TEST_CASE("AlwaysOddBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    AlwaysOddBetResultChecker odd_checker;
    RouletteResult even_result{2};
    RouletteResult odd_result{3};
    RouletteResult zero_result{0};


    REQUIRE_FALSE(odd_checker.won_bet(even_result));
    REQUIRE(odd_checker.won_bet(odd_result));
    REQUIRE_FALSE(odd_checker.won_bet(zero_result));
}

TEST_CASE("AlwaysLowBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    AlwaysLowBetResultChecker low_checker;
    RouletteResult low_result{1};
    RouletteResult high_result{19};
    RouletteResult zero_result{0};


    REQUIRE(low_checker.won_bet(low_result));
    REQUIRE_FALSE(low_checker.won_bet(high_result));
    REQUIRE_FALSE(low_checker.won_bet(zero_result));
}

TEST_CASE("AlwaysHighBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    AlwaysHighBetResultChecker high_checker;
    RouletteResult low_result{1};
    RouletteResult high_result{19};
    RouletteResult zero_result{0};


    REQUIRE_FALSE(high_checker.won_bet(low_result));
    REQUIRE(high_checker.won_bet(high_result));
    REQUIRE_FALSE(high_checker.won_bet(zero_result));
}
