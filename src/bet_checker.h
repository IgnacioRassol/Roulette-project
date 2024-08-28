#pragma once

#include "roulette_result.h"


// Bet result checker functions. These will be used by the player to
// check if they won the bet. They also represent the player's behavior.
// For example `AlwaysRedBetResultChecker` will mean that the player
// always bets red.

// AlwaysRedBetResultChecker returns true if the result is red.
bool AlwaysRedBetResultChecker(const RouletteResult&);

// AlwaysBlackBetResultChecker returns true if the result is black.
bool AlwaysBlackBetResultChecker(const RouletteResult&);

// AlwaysEvenBetResultChecker returns true if the result is even.
bool AlwaysEvenBetResultChecker(const RouletteResult&);

// AlwaysOddBetResultChecker returns true if the result is odd.
bool AlwaysOddBetResultChecker(const RouletteResult&);

// AlwaysLowBetResultChecker returns true if the result is low.
bool AlwaysLowBetResultChecker(const RouletteResult&);

// AlwaysHighBetResultChecker returns true if the result is high.
bool AlwaysHighBetResultChecker(const RouletteResult&);

