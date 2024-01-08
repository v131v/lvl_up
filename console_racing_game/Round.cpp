#include <ncurses.h>
#include <thread>
#include <algorithm>

#include "Round.h"
#include "Sprites.h"
#include "GameObjects.h"
#include "Generator.h"

Round* CreateRound(int w, int h) {
    //srand(time(0));

    Car *player = createCar();
    player->collider.approximate.x = (w - player->collider.approximate.w) / 2;
    player->collider.approximate.y = h - player->collider.approximate.h;

    Round *round = new Round();

    round->w = w;
    round->h = h;

    round->camX = 0;
    round->camY = 0;

    round->player = player;
    round->map = createMap(w, h);

    for (int i = 0; i < 4; i++) {
        Car *carLeft = createCar();
        carLeft->collider.approximate.x = round->map->x + 1;
        carLeft->collider.approximate.y = -i * (carLeft->collider.approximate.h + 2);

        Car *carRight = createCar();
        carRight->collider.approximate.x = round->map->x + (round->map->w - carRight->collider.approximate.w) - 1;
        carRight->collider.approximate.y = -i * (carRight->collider.approximate.h + 2);

        round->cars.push_back(carLeft);
        round->cars.push_back(carRight);
    }

    for (int i = 0; i < 3; i++) {
        Point *point = createPoint();
        point->collider.approximate.x = round->map->x + (round->map->w - point->collider.approximate.w) / 2;
        point->collider.approximate.y = -i * (point->collider.approximate.h + 4);

        round->points.push_back(point);
    }

    round->pathGenerator = CreatePathGenerator(w, -player->collider.approximate.h * 2 - 25);

    round->score = 0;
    round->passedMeters = 0;

    round->speed = 300;
    round->isActive = false;

    return round;
}

void EndRound(Round *round) {
    if (round == nullptr) return;

    delete round->map;
    delete round->player;
    for (auto &car : round->cars) {
        delete car;
    }
    delete round;
}

bool CheckCarsCollision(Round *round) {
    if (round == nullptr) return false;

    for (const auto &car : round->cars) {
        if (car->collider.approximate.y + car->collider.approximate.h < round->player->collider.approximate.y) {
            break;
        }

        if (HasCollision(car->collider, round->player->collider)) {
            return true;
        }
    }

    return false;
}

std::list<Point*>::iterator CheckPointsCollision(Car *player, std::list<Point*> &points) {
    if (player == nullptr) return points.end();

    for (auto it = points.begin(); it != points.end(); it++) {
        if ((*it)->collider.approximate.y + (*it)->collider.approximate.h < player->collider.approximate.y) {
            break;
        }

        if (HasCollision((*it)->collider, player->collider)) {
            return it;
        }
    }

    return points.end();
}

void clearDropped(Round *round) {
    if (round == nullptr) return;

    while (!round->cars.empty()) {
        Car *cur = round->cars.front();

        if (cur->collider.approximate.y <= round->h + round->camY) {
            break;
        }

        round->cars.pop_front();
        delete cur;
    }

    while (!round->points.empty()) {
        Point *cur = round->points.front();

        if (cur->collider.approximate.y <= round->h + round->camY) {
            break;
        }

        round->points.pop_front();
        delete cur;
    }
}

void RoundNextState(Round *round) {
    if (round == nullptr) return;

    while (round->isActive) {
        round->passedMeters++;
        round->speed = std::max(round->speed - 2, 80);

        round->camY--;
        round->map->y--;
        round->player->collider.approximate.y--;

        clearDropped(round);

        if (CheckCarsCollision(round)) {
            round->camY++;
            round->map->y++;
            round->player->collider.approximate.y++;
            return;
        }

        auto it = CheckPointsCollision(round->player, round->points);
        if (it != round->points.end()) {
            round->points.erase(it);
            round->score++;
        }

        Rectangle nextPathState = GenerateNextPath(round->pathGenerator, round->map);
        round->pathGenerator.rects.push_back(nextPathState);
        round->pathGenerator.rects.pop_front();

        Car *nextCar = GenerateNextCar(round->pathGenerator, round->map, round->cars, 66);
        if (nextCar != nullptr) {
            round->cars.push_back(nextCar);
        }

        Point *nextPoint = GenerateNextPoint(round->pathGenerator, 5);
        if (nextPoint != nullptr) {
            round->points.push_back(nextPoint);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(round->speed));
    }
}
