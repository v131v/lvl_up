#ifndef ROUND_H
#define ROUND_H

#include <list>

#include "Collider.h"
#include "GameObjects.h"

struct Round {
    int w;
    int h;

    int camX;
    int camY;

    Car *player;
    Map *map;
    std::list<Car*> cars;
    std::list<Point*> points;

    BiasedCollider pathGenerator;

    int score;
    int passedMeters;

    int speed;
    bool isActive;
};

Round* CreateRound(int w, int h);

void EndRound(Round *round);

bool CheckCarsCollision(Round *round);

std::list<Point*>::iterator CheckPointsCollision(Car *player, std::list<Point*> &points);

void RoundNextState(Round *round);

#endif // ROUND_H
