#include "Generator.h"

BiasedCollider CreatePathGenerator(int w, int y) {
    BiasedCollider pathGenerator;
    Collider carCollider = CreateCarCollider();

    Rectangle carApproximate = carCollider.approximate;
    carApproximate.w++;
    carApproximate.h++;

    carApproximate.x = (w - carApproximate.w) / 2;
    carApproximate.y = y;

    for (int i = 0; i < carApproximate.h * 2; i++) {
        pathGenerator.rects.push_back(carApproximate);

        int rnd = rand() % 3 - 1;
        carApproximate.x += rnd;
        carApproximate.y--;
    }

    return pathGenerator;
}

Rectangle GenerateNextPath(const BiasedCollider &pathGen, Map *map) {
    Rectangle nextPathState = pathGen.rects.back();

    int rnd = rand() % 3 - 1;
    nextPathState.y--;
    nextPathState.x += rnd;

    if (nextPathState.x < map->x + 1 || nextPathState.x + nextPathState.w > map->x + map->w - 2) {
        nextPathState.x -= rnd;
    }

    return nextPathState;
}

Car* GenerateNextCar(const BiasedCollider &pathGen, Map *map, const std::list<Car*> &cars, int probability) {
    if (rand() % 100 >= probability) return nullptr;

    Car *car = createCar();
    Rectangle last = pathGen.rects.back();
    car->collider.approximate.y = last.y + last.h;

    std::vector<int> avaliableX;
    for (int x = map->x + 1; x < map->x + map->w - car->collider.approximate.w - 1; x++) {
        car->collider.approximate.x = x;

        if (HasCollision(car->collider, pathGen)) {
            continue;
        }

        bool hasCollision = false;
        auto it = cars.rbegin();
        for (int i = 0; i < car->collider.approximate.h && it != cars.rend(); i++) {
            if (HasRectanglesCollision(car->collider.approximate, (*it)->collider.approximate)) {
                hasCollision = true;
                break;
            }
            it++;
        }

        if (!hasCollision) {
            avaliableX.push_back(x);
        }
    }

    if (avaliableX.size() == 0) return nullptr;

    car->collider.approximate.x = avaliableX[rand() % avaliableX.size()];
    return car;
}

Point* GenerateNextPoint(const BiasedCollider &pathGen, int probability) {
    if (rand() % 100 >= probability) return nullptr;

    Point *point = createPoint();
    Rectangle last = pathGen.rects.back();
    point->collider.approximate.y = last.y;
    point->collider.approximate.x = last.x + (last.w - point->collider.approximate.w) / 2;

    return point;
}
