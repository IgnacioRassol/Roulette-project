#include <iostream>
#include <vector>

#include "player.h"
#include "bet_checker.h"
#include "roulette.h"

void simulation(int number_rounds) {

    Player playerA (std::make_unique<AlwaysRedBetResultChecker>());

    Player playerB (std::make_unique<AlwaysBlackBetResultChecker>());

    Player playerC (std::make_unique<AlwaysHighBetResultChecker>());

    Player playerD (std::make_unique<AlwaysLowBetResultChecker>());

    Player playerE (std::make_unique<AlwaysEvenBetResultChecker>());

    Player playerF (std::make_unique<AlwaysOddBetResultChecker>());

    Roulette roulette;

    for (int i = 0; i < number_rounds; i++) {
        RouletteResult result{roulette.spin()};

        std::cout << "Round " << i << std::endl;
        std::cout << "Number: " << result.get_result() << std::endl;
        std::cout << "Red: " << result.result_is_red() 
                    << " High: " << result.result_is_high()
                    << " Even: " << result.result_is_even()
                    << std::endl;

        playerA.play(result);
        playerB.play(result);
        playerC.play(result);
        playerD.play(result);
        playerE.play(result);
        playerF.play(result);

        std::cout << playerA.get_bet_balance() << " "
                    << playerB.get_bet_balance() << " "
                    << playerC.get_bet_balance() << " "
                    << playerD.get_bet_balance() << " "
                    << playerE.get_bet_balance() << " "
                    << playerF.get_bet_balance() << " "
                    << std::endl;

        std::cout << std::endl;
    }

    

}
