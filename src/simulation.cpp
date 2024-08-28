#include <iostream>
#include <vector>
#include <memory>

#include "player.h"
#include "bet_checker.h"
#include "roulette.h"
#include "simulation.h"
#include "config.h"

void default_simulation() {
    std::vector<Player> players{
        Player(AlwaysRedBetResultChecker, "Always Red"),
        Player(AlwaysBlackBetResultChecker, "Always Black"),
        Player(AlwaysHighBetResultChecker, "Always High"),
        Player(AlwaysLowBetResultChecker, "Always Low"),
        Player(AlwaysEvenBetResultChecker, "Always Even"),
        Player(AlwaysOddBetResultChecker, "Always Odd")
    };

    simulation(config::number_of_rounds, players);

    display_simulation_results(players);
}

void simulation(int number_rounds, std::vector<Player>& players) {
    Roulette roulette;

    for (int i = 0; i < number_rounds; i++) {
        RouletteResult result{roulette.spin()};

        for (Player &player : players) {
            player.play(result);
        }
    }
}

void display_simulation_results(const std::vector<Player>& players) {
    int team_balance {0};

    for (const Player& player : players) {
        std::cout << "Player: " << player.get_name() << std::endl;
        std::cout << "Balance: " << player.get_bet_balance() << std::endl;

        team_balance += player.get_bet_balance();
    }

    std::cout << std::endl;
    std::cout << "Team Balance: " << team_balance << std::endl;
}
