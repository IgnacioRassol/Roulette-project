#include <fstream>

#include "player.h"
#include "catch_amalgamated.hpp"

TEST_CASE("Player correctly updates bet balance and history", "[player]") {
    std::shared_ptr<AlwaysRedBetResultChecker> red_checker = std::make_shared<AlwaysRedBetResultChecker>();
    Player player{red_checker, "test"};

    REQUIRE(player.get_bet_balance() == 0);
    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4});

    player.play(RouletteResult{1});
    REQUIRE(player.get_bet_balance() == 5);
    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4,5});

    player.play(RouletteResult{2});
    REQUIRE(player.get_bet_balance() == -1);
    REQUIRE(player.get_bet_history() == std::list<int>{2,3,4});

    player.play(RouletteResult{1});
    REQUIRE(player.get_bet_balance() == 5);
    REQUIRE(player.get_bet_history() == std::list<int>{2,3,4,6});
}

TEST_CASE("Player correctly resets bet history when it runs out of numbers", "[player]") {
    std::shared_ptr<AlwaysRedBetResultChecker> red_checker = std::make_shared<AlwaysRedBetResultChecker>();
    Player player{red_checker, "test"};


    REQUIRE(player.get_bet_balance() == 0);
    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4});

    player.play(RouletteResult{2});
    player.play(RouletteResult{2});

    REQUIRE(player.get_bet_history() == std::list<int>{});

    player.play(RouletteResult{1});
    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4,5});
}

TEST_CASE("Player correctly resets bet history when next bet is lower than table min", "[player]") {
    std::shared_ptr<AlwaysRedBetResultChecker> red_checker = std::make_shared<AlwaysRedBetResultChecker>();
    Player player{red_checker, "test"};

    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4});

    player.play(RouletteResult{2});
    player.play(RouletteResult{1});
    REQUIRE(player.get_bet_history() == std::list<int>{2,3,5});


    player.play(RouletteResult{2});

    REQUIRE(player.get_bet_history() == std::list<int>{3});

    player.play(RouletteResult{1});
    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4,5});
}

TEST_CASE("Player correctly resets bet history when next bet is higher than table max", "[player]") {
    std::shared_ptr<AlwaysRedBetResultChecker> red_checker = std::make_shared<AlwaysRedBetResultChecker>();
    Player player{red_checker, "test", false, 5, 10};

    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4});

    player.play(RouletteResult{1});
    player.play(RouletteResult{1});
    player.play(RouletteResult{1});
    player.play(RouletteResult{1});
    player.play(RouletteResult{1});
    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4,5,6,7,8,9});

    player.play(RouletteResult{1});

    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4,5,6,7,8,9,10});

    player.play(RouletteResult{1});
    REQUIRE(player.get_bet_history() == std::list<int>{1,2,3,4,5});
}


TEST_CASE("Player correctly logs results", "[player]") {
    std::shared_ptr<AlwaysRedBetResultChecker> red_checker = std::make_shared<AlwaysRedBetResultChecker>();
    Player player{red_checker, "test", true};

    player.play(RouletteResult{1});
    player.play(RouletteResult{2});
    player.play(RouletteResult{1});

    std::ifstream inf{"test.csv"};
    std::string line;
    std::getline(inf, line);
    REQUIRE(line == "Roulette Result, Won, Balance, Bet History");

    std::getline(inf, line);
    REQUIRE(line == "1, won, 5, 1 2 3 4 5 ");

    std::getline(inf, line);
    REQUIRE(line == "2, lost, -1, 2 3 4 ");

    std::getline(inf, line);
    REQUIRE(line == "1, won, 5, 2 3 4 6 ");
}