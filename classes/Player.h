#ifndef PLAYER_H
#define PLAYER_H

class Player {
    int x;
    int y;
    char symbol;

    public:
        Player(int startX, int startY, char s);

        int getX() const { return x; }
        int getY() const { return y; }
        char getSymbol() const { return symbol; }
        void move(int dx, int dy);
};

#endif
