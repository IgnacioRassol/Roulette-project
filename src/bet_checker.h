#pragma once

#include "roulette_result.h"


// Abstract base class of BetCheckers. These will be used by the player to 
// check if they won the bet. They also represent the player's behavior.
// For example `AlwaysRedBetResultChecker` will mean that the player 
// always bets red.
class IBetResultChecker {
    public:
        virtual ~IBetResultChecker() = default;
        virtual bool won_bet(const RouletteResult& result) const = 0;
};

class AlwaysRedBetResultChecker : public IBetResultChecker {
    public:
        bool won_bet(const RouletteResult& result) const override;
};

class AlwaysBlackBetResultChecker : public IBetResultChecker {
    public:
        bool won_bet(const RouletteResult& result) const override;
};

class AlwaysEvenBetResultChecker : public IBetResultChecker {
    public:
        bool won_bet(const RouletteResult& result) const override;
};

class AlwaysOddBetResultChecker : public IBetResultChecker {
    public:
        bool won_bet(const RouletteResult& result) const override;
};

class AlwaysLowBetResultChecker : public IBetResultChecker {
    public:
        bool won_bet(const RouletteResult& result) const override;
};

class AlwaysHighBetResultChecker : public IBetResultChecker {
    public:
        bool won_bet(const RouletteResult& result) const override;
};

