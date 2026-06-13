#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include "Point.h"

struct Player {
    Player(int x, int y, char s)
        : symbol(s){
            body.emplace_back(x,y);
        }

    std::list<Point> body;
    char symbol;

    void move(int dx, int dy, bool grow) {
        Point currentHead = body.front();
        Point newHead = {currentHead.x + dx, currentHead.y + dy};
        body.push_front(newHead);
        if (!grow) body.pop_back();
    }

    void grow(int dx, int dy) {
        Point currentHead = body.front();
        Point newHead = {currentHead.x + dx, currentHead.y + dy};
        body.push_front(newHead);
    }

    Point& getHead() { return body.front(); }

};


#endif
