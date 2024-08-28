#pragma once

#include <vector>

#include "player.h"

void default_simulation();

void simulation(int number_rounds, std::vector<Player>& players);

void display_simulation_results(const std::vector<Player>& players);
