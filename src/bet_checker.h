#pragma once

#include "roulette_result.h"


// Bet result checker functions. These will be used by the player to
// check if they won the bet. They also represent the player's behavior.
// For example `AlwaysRedBetResultChecker` will mean that the player
// always bets red.

bool AlwaysRedBetResultChecker(const RouletteResult&);
bool AlwaysBlackBetResultChecker(const RouletteResult&);
bool AlwaysEvenBetResultChecker(const RouletteResult&);
bool AlwaysOddBetResultChecker(const RouletteResult&);
bool AlwaysLowBetResultChecker(const RouletteResult&);
bool AlwaysHighBetResultChecker(const RouletteResult&);

