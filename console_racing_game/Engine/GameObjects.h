#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "Draw/SpriteDraw.h"
#include "Collider.h"

struct Car {
    Collider collider;
    Sprite sprite;
};

struct Point {
    Collider collider;
    Sprite sprite;
};

struct Map {
    int x;
    int y;
    int w;
    int h;
    Sprite sprite;
};

Collider CreateCarCollider();

Car* createCar();

Point* createPoint();

Map* createMap(int w, int h);

#endif // GAMEOBJECTS_H
