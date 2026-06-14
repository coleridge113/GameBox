#include "headers/Player.h"
#include "headers/TerminalState.h"
#include "headers/GameState.h"
#include "utils/Utils.h"
#include <iostream>
#include <ostream>
#include <termios.h>
#include <unistd.h>

using namespace std;

int main() {
    TerminalState ts;
    GameState gs{10, 10};
    Player p{1, 2, '@'};
    Player f{generateRandomNumber(gs.boundXY), gs.boundXY, 'X'};

    while (!gs.checkWin()) {
        cout << "\033[2J\033[1;1H";
        gs.updateState(p, f);

        char input = getch();
        if (input == 'w' && p.getHead().y > 0) {  
            p.move(0, -1); 
        }
        if (input == 's' && p.getHead().y < gs.boundXY) { 
            p.move(0, 1); 
        }
        if (input == 'a' && p.getHead().x > 0) { 
            p.move(-1, 0); 
        }
        if (input == 'd' && p.getHead().x < gs.boundXY) { 
            p.move(1, 0); 
        }
    }

    cout << "You won!" << endl;
    return 0;
}
