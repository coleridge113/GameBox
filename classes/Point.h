#ifndef POINT_H
#define POINT_H

struct Point {
    Point(int x, int y)
        : x(x), y(y) {}

    int x;
    int y;
};

#endif
