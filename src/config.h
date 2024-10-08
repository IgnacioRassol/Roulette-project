#pragma once

// Simulation configuration
namespace config {
    // Number of rounds that will be simulated
    constexpr int number_of_rounds = 10000;
    // Flag to indicate if the players should log their activity to a file
    constexpr bool should_log = true;
    // Minimum allowed bet at the table
    constexpr int bet_lower_bound = 5;
    // Maximum allowed bet at the table
    constexpr int bet_upper_bound = 4000;
}
