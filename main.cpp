#include "classes/Player.h"
#include "classes/TerminalState.h"
#include "classes/GameState.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>

char getch() {
    char buf = 0;
    read(0, &buf, 1);
    return buf;
}

int main() {
    TerminalState ts;
    Player p = Player(1, 1, '@');
    GameState gs = GameState(5, 10);

    while (!gs.checkWin()) {
        std::cout << "\033[2J\033[1;1H";
        gs.updateState(p);

        char input = getch();
        if (input == 'w' && p.getY() > 0) {  
            p.move(0, -1); 
        }
        if (input == 's' && p.getY() < gs.getBound()) { 
            p.move(0, 1); 
        }
        if (input == 'a' && p.getX() > 0) { 
            p.move(-1, 0); 
        }
        if (input == 'd' && p.getX() < gs.getBound()) { 
            p.move(1, 0); 
        }
    }
    return 0;
}
