#include "GameState.h"
#include <iostream>

GameState::GameState(int grid, int targetScore)
    : grid(grid), targetScore(targetScore) {}

void GameState::updateState(Player& player) {
        for (int i = 0; i < grid; ++i) {
            for (int j = 0; j < grid; ++j) {
                if (i == player.getY() && j == player.getX()) {
                    std::cout << player.getSymbol() << " ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << "\n";
        }
}
