#include "headers/Player.h"
#include "headers/TerminalState.h"
#include "headers/GameState.h"
#include "utils/Utils.h"
#include <atomic>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <ostream>
#include <termios.h>
#include <thread>
#include <unistd.h>


std::atomic<bool> inputReceived(false);
char input = 0;

std::mutex mtx;
std::condition_variable cv;

void inputThread() {
    char c = 'd';
    while (true) {
        std::cin >> c;
        {
            std::lock_guard<std::mutex> lock(mtx);
            input = c;
            inputReceived = true;
        }
        cv.notify_one();
    }
}

int main() {
    std::thread t(inputThread);
    t.detach();

    TerminalState ts;
    GameState gs{10, 10};
    Player p{
        {Point{1, 2}}, '@'
    };
    Player f{
        {Point{generateRandomNumber(gs.boundXY), generateRandomNumber(gs.boundXY)}},
        'X'
    };

    char prev = input;

    while (!gs.checkWin()) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait_for(lock, std::chrono::seconds(1), [] { return inputReceived.load(); });
        std::cout << "\033[2J\033[1;1H";
        gs.updateState(p, f);

        if (input == 0) {
            input = prev;
        }

        if (inputReceived) {
            prev = input;
            input = 0;
            inputReceived = false;
        }

        if (input == 'w' && 
            p.getHead().y > 0 && 
            p.opposite[prev] != input
        ) {  
            p.move(0, -1); 
        }
        if (input == 's' && 
            p.getHead().y < gs.boundXY &&
            p.opposite[prev] != input
        ) {  
            p.move(0, 1); 
        }
        if (input == 'a' && 
            p.getHead().x > 0 &&
            p.opposite[prev] != input
        ) {  
            p.move(-1, 0); 
        }
        if (input == 'd' && 
            p.getHead().x < gs.boundXY &&
            p.opposite[prev] != input
        ) {  
            p.move(1, 0); 
        }
    }

    std::cout << "You won!" << std::endl;
    return 0;
}
