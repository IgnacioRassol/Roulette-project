#include "roulette_result.h"
#include "player.h"
#include "bet_checker.h"
#include "roulette.h"
#include <iostream>

int main(){
    Roulette roulette;
    RouletteResult result{roulette.spin()};
    std::cout << "Result: " << result.get_result() << std::endl;
    std::cout << "Is red: " << result.result_is_red() << std::endl;
    std::cout << "Is black: " << result.result_is_black() << std::endl;
    std::cout << "Is even: " << result.result_is_even() << std::endl;
    std::cout << "Is odd: " << result.result_is_odd() << std::endl;
    std::cout << "Is low: " << result.result_is_low() << std::endl;
    std::cout << "Is high: " << result.result_is_high() << std::endl;


    AlwaysRedBetResultChecker bet_checker;
    Player player(bet_checker);

    player.play(result);

    player.print_bet_history();

    return 0;
}
