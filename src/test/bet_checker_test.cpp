#include "bet_checker.h"
#include "catch_amalgamated.hpp"

TEST_CASE("AlwaysRedBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    RouletteResult red_result{1};
    RouletteResult black_result{2};
    RouletteResult zero_result{0};

    REQUIRE(AlwaysRedBetResultChecker(red_result));
    REQUIRE_FALSE(AlwaysRedBetResultChecker(black_result));
    REQUIRE_FALSE(AlwaysRedBetResultChecker(zero_result));
}

TEST_CASE("AlwaysBlackBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    RouletteResult red_result{1};
    RouletteResult black_result{2};
    RouletteResult zero_result{0};


    REQUIRE_FALSE(AlwaysBlackBetResultChecker(red_result));
    REQUIRE(AlwaysBlackBetResultChecker(black_result));
    REQUIRE_FALSE(AlwaysBlackBetResultChecker(zero_result));
}


TEST_CASE("AlwaysEvenBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    RouletteResult even_result{2};
    RouletteResult odd_result{3};
    RouletteResult zero_result{0};


    REQUIRE(AlwaysEvenBetResultChecker(even_result));
    REQUIRE_FALSE(AlwaysEvenBetResultChecker(odd_result));
    REQUIRE_FALSE(AlwaysEvenBetResultChecker(zero_result));
}

TEST_CASE("AlwaysOddBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    RouletteResult even_result{2};
    RouletteResult odd_result{3};
    RouletteResult zero_result{0};


    REQUIRE_FALSE(AlwaysOddBetResultChecker(even_result));
    REQUIRE(AlwaysOddBetResultChecker(odd_result));
    REQUIRE_FALSE(AlwaysOddBetResultChecker(zero_result));
}

TEST_CASE("AlwaysLowBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    RouletteResult low_result{1};
    RouletteResult high_result{19};
    RouletteResult zero_result{0};


    REQUIRE(AlwaysLowBetResultChecker(low_result));
    REQUIRE_FALSE(AlwaysLowBetResultChecker(high_result));
    REQUIRE_FALSE(AlwaysLowBetResultChecker(zero_result));
}

TEST_CASE("AlwaysHighBetResultChecker correctly identifies winning bets", "[bet_checker]") {
    RouletteResult low_result{1};
    RouletteResult high_result{19};
    RouletteResult zero_result{0};


    REQUIRE_FALSE(AlwaysHighBetResultChecker(low_result));
    REQUIRE(AlwaysHighBetResultChecker(high_result));
    REQUIRE_FALSE(AlwaysHighBetResultChecker(zero_result));
}
