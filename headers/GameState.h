#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../utils/Utils.h"
#include "Player.h"
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

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
        if (checkCollision(player, food)) {
            incrementScore();
            regenerateFood(food);
            player.grow = true;
        }
        printScore(score);
        printGrid(player, food);
    }

    bool checkCollision(Player& player, Player& food) {
        return player.getHead().x == food.getHead().x 
            && player.getHead().y == food.getHead().y;
    }

    void printScore(int& score) {
        cout << "Score: " << score << endl;
    }


    void printGrid(Player& player, Player& food) {
        vector<vector<char>> gridMap(grid, vector<char>(grid, '.'));

        for (const auto& point : player.body) {
            if (point.x >= 0 && point.x < grid && point.y >= 0 && point.y < grid) {
                gridMap[point.y][point.x] = '@';
            }
        }

        gridMap[food.getHead().y][food.getHead().x] = food.symbol;

        for (int i = 0; i < grid; ++i) {
            for (int j = 0; j < grid; ++j) {
                cout << gridMap[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void regenerateFood(Player& food) {
        int nx = generateRandomNumber(boundXY);
        int ny = generateRandomNumber(boundXY);

        food.getHead().x = nx;
        food.getHead().y = ny;
    }
};

#endif
