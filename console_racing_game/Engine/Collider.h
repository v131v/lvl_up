#ifndef COLLIDER_H
#define COLLIDER_H

#include <list>

struct Rectangle {
    int w = 0;
    int h = 0;
    int x = 0;
    int y = 0;
};

struct Collider {
    Rectangle approximate;
    std::list<Rectangle> rects;
};

struct BiasedCollider {
    std::list<Rectangle> rects;
};

bool HasRectanglesCollision(const Rectangle &a, const Rectangle &b);
Rectangle ApproximateRects(std::list<Rectangle> &rects);

BiasedCollider ApplyBias(const Collider &collider);

bool HasCollision(const Collider &a, const Collider &b);
bool HasCollision(const BiasedCollider &a, const Collider &b);
bool HasCollision(const Collider &a, const BiasedCollider &b);
bool HasCollision(const BiasedCollider &a, const BiasedCollider &b);

#endif // COLLIDER_H
