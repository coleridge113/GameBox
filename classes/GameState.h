#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Player.h"

class GameState {
    int grid;
    int boundXY = grid - 1;
    int score = 0;
    int targetScore;

    public:
        GameState(int grid, int targetScore);
        int getGridSize() { return grid; }
        int getBound() { return boundXY; }
        int getScore() { return score; }
        void incrementScore() { ++score; }
        bool checkWin() { return score == targetScore; }
        void updateState(Player& player, Player& food);
};

#endif
