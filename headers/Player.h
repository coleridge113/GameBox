#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include "Point.h"
#include <map>

struct Player {
    std::list<Point> body;
    char symbol;
    std::map<char, char> opposite{
        {'w', 's'},
        {'s', 'w'},
        {'a', 'd'},
        {'d', 'a'}
    };
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
