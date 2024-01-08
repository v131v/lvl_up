#include "Collider.h"


bool HasRectanglesCollision(const Rectangle &a, const Rectangle &b) {
    int xCollide, yCollide;

    if (a.x < b.x) {
        xCollide = a.x + a.w - b.x;
    } else {
        xCollide = b.x + b.w - a.x;
    }

    if (a.y < b.y) {
        yCollide = a.y + a.h - b.y;
    } else {
        yCollide = b.y + b.h - a.y;
    }

    return xCollide > 0 && yCollide > 0;
}

BiasedCollider ApplyBias(const Collider &collider) {
    BiasedCollider biased{ .rects = collider.rects };

    for (auto &rect : biased.rects) {
        rect.x += collider.approximate.x;
        rect.y += collider.approximate.y;
    }

    return biased;
}

bool HasCollision(const Collider &a, const Collider &b) {
    bool isApproximateCollide = HasRectanglesCollision(a.approximate, b.approximate);
    if (!isApproximateCollide) return false;

    const BiasedCollider aBiased = ApplyBias(a);
    const BiasedCollider bBiased = ApplyBias(b);

    return HasCollision(aBiased, bBiased);
}

bool HasCollision(const Collider &a, const BiasedCollider &b) {
    const BiasedCollider aBiased = ApplyBias(a);
    return HasCollision(aBiased, b);
}

bool HasCollision(const BiasedCollider &a, const Collider &b) {
    return HasCollision(b, a);
}

bool HasCollision(const BiasedCollider &a, const BiasedCollider &b) {
    for (const auto &rectA : a.rects) {

        for (const auto &rectB : b.rects) {

            if (HasRectanglesCollision(rectA, rectB)) {
                return true;
            }
        }
    }

    return false;
}

Rectangle ApproximateRects(std::list<Rectangle> &rects) {
    Rectangle approximate = *rects.begin();

    for (const auto &rect : rects) {
        approximate.x = std::min(approximate.x, rect.x);
        approximate.y = std::min(approximate.y, rect.y);
        approximate.w = std::max(approximate.x + approximate.w, rect.x + rect.w) - approximate.w;
        approximate.h = std::max(approximate.y + approximate.h, rect.y + rect.h) - approximate.h;
    }

    return approximate;
}
