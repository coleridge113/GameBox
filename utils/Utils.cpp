#include "Utils.h"
#include <chrono>
#include <fcntl.h>
#include <thread>

char getch() {
    char buf = 0;
    read(0, &buf, 1);
    return buf;
}

char getch_nb() {
    char buf = 0;
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    if (read(STDIN_FILENO, &buf, 1) > 0) {
        return buf;
    }
    return 0;
}

int generateRandomNumber(int upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(1, upperBound);
    return distr(gen);
}

void sleep(int t) {
    std::this_thread::sleep_for(std::chrono::milliseconds(t));
}
