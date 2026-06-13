#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Player.h"
#include <iostream>

struct GameState {
    GameState(int grid, int targetScore)
        : grid(grid), targetScore(targetScore){
            boundXY = grid - 1;
            score = 0;
        };

    int grid;
    int boundXY;
    int score;
    int targetScore;
    void incrementScore() { ++score; }
    bool checkWin() { return score == targetScore; }

    void updateState(Player& player, Player& food){
        for (int i = 0; i < grid; ++i) {
            for (int j = 0; j < grid; ++j) {
                if (i == player.y && j == player.x) {
                    std::cout << player.symbol << " ";
                } else if (i == food.y && j == food.x) {
                    std::cout << food.symbol << " ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << "\n";
        }
    };
};

#endif
