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
    bool grow = false;

    void move(int dx, int dy) {
        Point currentHead = body.front();
        Point newHead = {currentHead.x + dx, currentHead.y + dy};
        body.push_front(newHead);
        if (!grow) {
            body.pop_back();
        } else {
            grow = false;
        }
    }

    Point& getHead() { return body.front(); }

};


#endif
