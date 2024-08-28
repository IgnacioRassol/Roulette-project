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
        Player(std::make_shared<AlwaysRedBetResultChecker>(), "Always Red"),
        Player(std::make_shared<AlwaysBlackBetResultChecker>(), "Always Black"),
        Player(std::make_shared<AlwaysHighBetResultChecker>(), "Always High"),
        Player(std::make_shared<AlwaysLowBetResultChecker>(), "Always Low"),
        Player(std::make_shared<AlwaysEvenBetResultChecker>(), "Always Even"),
        Player(std::make_shared<AlwaysOddBetResultChecker>(), "Always Odd")
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

void display_simulation_results(std::vector<Player>& players) {
    int team_balance {0};

    for (Player &player : players) {
        std::cout << "Player: " << player.get_name() << std::endl;
        std::cout << "Balance: " << player.get_bet_balance() << std::endl;

        team_balance += player.get_bet_balance();
    }

    std::cout << std::endl;
    std::cout << "Team Balance: " << team_balance << std::endl;
}