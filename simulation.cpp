#include <iostream>
#include <vector>

#include "player.h"
#include "bet_checker.h"
#include "roulette.h"
#include "simulation.h"

void default_simulation(){
    std::vector<Player> players{
        Player(std::make_shared<AlwaysRedBetResultChecker>(), "Always Red", true),
        Player(std::make_shared<AlwaysBlackBetResultChecker>(), "Always Black", true),
        Player(std::make_shared<AlwaysHighBetResultChecker>(), "Always High", true),
        Player(std::make_shared<AlwaysLowBetResultChecker>(), "Always Low", true),
        Player(std::make_shared<AlwaysEvenBetResultChecker>(), "Always Even", true),
        Player(std::make_shared<AlwaysOddBetResultChecker>(), "Always Odd", true)
    };

    simulation(10, players);
}

void simulation(int number_rounds, std::vector<Player> players) {

    Roulette roulette;

    for (int i = 0; i < number_rounds; i++) {
        RouletteResult result{roulette.spin()};

        for (Player &player : players) {
            player.play(result);
        }
    }
}
