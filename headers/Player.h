#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include "Point.h"
#include <map>

using namespace std;

struct Player {
    Player(int x, int y, char s)
        : symbol(s) {
            body.emplace_back(x,y);
        }

    list<Point> body;
    map<char, char> opposite{
        {'w', 's'},
        {'s', 'w'},
        {'a', 'd'},
        {'d', 'a'}
    };
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
