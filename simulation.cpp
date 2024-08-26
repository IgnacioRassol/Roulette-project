#include <iostream>
#include <vector>

#include "player.h"
#include "bet_checker.h"
#include "roulette.h"
#include "simulation.h"

void default_simulation(){
    std::vector<Player> players{
        Player(std::make_shared<AlwaysRedBetResultChecker>(), "Always Red"),
        Player(std::make_shared<AlwaysBlackBetResultChecker>(), "Always Black"),
        Player(std::make_shared<AlwaysHighBetResultChecker>(), "Always High"),
        Player(std::make_shared<AlwaysLowBetResultChecker>(), "Always Low"),
        Player(std::make_shared<AlwaysEvenBetResultChecker>(), "Always Even"),
        Player(std::make_shared<AlwaysOddBetResultChecker>(), "Always Odd")
    };

    simulation(10, players, true);
}

void simulation(int number_rounds, std::vector<Player> players, bool should_log) {

    Roulette roulette;

    if (should_log) {
        for (Player &player : players) {
            player.init_log();
        }
    }

    for (int i = 0; i < number_rounds; i++) {
        RouletteResult result{roulette.spin()};

        for (Player &player : players) {
            player.play(result);
            
            if (should_log) {
                player.update_log(result.get_result());
            }
        }
    }

    

}
