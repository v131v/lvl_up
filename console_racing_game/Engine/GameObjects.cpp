#include "GameObjects.h"
#include "Sprites.h"

Collider CreateCarCollider() {
    Collider carCollider;
    carCollider.approximate = Rectangle{ .w = CarSprite.w, .h = CarSprite.h, .x = 0, .y = 0 };
    carCollider.rects = {
        Rectangle{ .w = 1, .h = 3, .x = 1, .y = 0 },
        Rectangle{ .w = 3, .h = 1, .x = 0, .y = 1 },
        Rectangle{ .w = 1, .h = 1, .x = 0, .y = 3 },
        Rectangle{ .w = 1, .h = 1, .x = 2, .y = 3 },
    };
    return carCollider;
}

Car* createCar() {
    Car *car = new Car();

    car->sprite = CarSprite;
    car->collider = CreateCarCollider();

    return car;
}

Point* createPoint() {
    Point *point = new Point();
    point->sprite = PointSprite;
    point->collider = Collider{
        .approximate = Rectangle{ .w = PointSprite.w, .h = PointSprite.h },
        .rects = {
            Rectangle{ .w = 3, .h = 1, .x = 0, .y = 1 },
            Rectangle{ .w = 1, .h = 3, .x = 1, .y = 0 },
        }
    };
    return point;
}

Map* createMap(int w, int h) {
    Map *map = new Map();

    map->w = MapSprite.w;
    map->h = h;
    map->sprite = MapSprite;

    map->x = (w - map->w) / 2;
    map->y = 0;

    return map;
}
