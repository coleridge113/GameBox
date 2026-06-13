#ifndef PLAYER_H
#define PLAYER_H

struct Player {
    Player(int startX, int startY, char s)
        : x(startX), y(startY), symbol(s){}

    int x;
    int y;
    char symbol;
    void move(int dx, int dy){
        x += dx;
        y += dy;
    };
};

#endif
