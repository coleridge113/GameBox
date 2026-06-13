#include "classes/Player.h"
#include "classes/TerminalState.h"
#include "classes/GameState.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <random>

char getch() {
    char buf = 0;
    read(0, &buf, 1);
    return buf;
}

int generateRandomNumber(int upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, upperBound);
    return distr(gen);
}

int main() {
    TerminalState ts;
    GameState gs{5, 10};
    Player p{1, 1, '@'};
    Player f{generateRandomNumber(gs.boundXY), gs.boundXY, 'X'};

    while (!gs.checkWin()) {
        std::cout << "\033[2J\033[1;1H";
        gs.updateState(p, f);

        char input = getch();
        if (input == 'w' && p.y > 0) {  
            p.move(0, -1); 
        }
        if (input == 's' && p.y < gs.boundXY) { 
            p.move(0, 1); 
        }
        if (input == 'a' && p.x > 0) { 
            p.move(-1, 0); 
        }
        if (input == 'd' && p.x < gs.boundXY) { 
            p.move(1, 0); 
        }
    }
    return 0;
}
