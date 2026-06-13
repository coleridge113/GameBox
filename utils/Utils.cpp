#include "Utils.h"

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
