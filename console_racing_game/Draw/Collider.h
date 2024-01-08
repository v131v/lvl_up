#ifndef COLLIDER_H
#define COLLIDER_H

#include <vector>

struct Rectangle {
    int w;
    int h;
    int x;
    int y;
};

struct Collider {
    std::vector<Rectangle> rects;
};

#endif // COLLIDER_H
