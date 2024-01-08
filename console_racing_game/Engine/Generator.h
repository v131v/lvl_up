#ifndef GENERATOR_H
#define GENERATOR_H

#include "Collider.h"
#include "GameObjects.h"

BiasedCollider CreatePathGenerator(int w, int y);

Rectangle GenerateNextPath(const BiasedCollider &pathGen, Map *map);

Car* GenerateNextCar(const BiasedCollider &pathGen, Map *map, const std::list<Car*> &cars, int probability);

Point* GenerateNextPoint(const BiasedCollider &pathGen, int probability);

#endif // GENERATOR_H
