#pragma once

#include <vector>

#include "player.h"

// Simulation with default parameters and players, as specified in the requirements.
void default_simulation();

// Given a number of rounds and a list of players, simulates a roulette game.
void simulation(int number_rounds, std::vector<Player>& players);

// Displays the player balances after running the simulation.
void display_simulation_results(const std::vector<Player>& players);
