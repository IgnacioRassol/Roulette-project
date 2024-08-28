#include "roulette_result.h"
#include "catch_amalgamated.hpp"


TEST_CASE("Roulette result correctly identifies 0", "[roulette_result]") {
    RouletteResult zero_result{0};

    REQUIRE_FALSE(zero_result.result_is_even());
    REQUIRE_FALSE(zero_result.result_is_low());
    REQUIRE_FALSE(zero_result.result_is_red());
}

TEST_CASE("Roulette result correctly identifies color", "[roulette_result]") {
    RouletteResult red_result{1};
    RouletteResult black_result{2};

    REQUIRE(red_result.result_is_red());
    REQUIRE_FALSE(red_result.result_is_black());
    REQUIRE_FALSE(black_result.result_is_red());
    REQUIRE(black_result.result_is_black());
}

TEST_CASE("Roulette result correctly identifies even/odd", "[roulette_result]") {
    RouletteResult even_result{2};
    RouletteResult odd_result{3};

    REQUIRE(even_result.result_is_even());
    REQUIRE_FALSE(even_result.result_is_odd());
    REQUIRE_FALSE(odd_result.result_is_even());
    REQUIRE(odd_result.result_is_odd());
}

TEST_CASE("Roulette result correctly identifies high/low", "[roulette_result]") {
    RouletteResult low_result{1};
    RouletteResult high_result{19};

    REQUIRE(low_result.result_is_low());
    REQUIRE_FALSE(low_result.result_is_high());
    REQUIRE_FALSE(high_result.result_is_low());
    REQUIRE(high_result.result_is_high());
}