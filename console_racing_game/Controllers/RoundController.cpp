#include <algorithm>

#include "Round.h"

void RoundMoveLeft(Round *round) {
    if (round == nullptr) return;

    int lastX = round->player->collider.approximate.x;

    round->player->collider.approximate.x = std::max(
                round->player->collider.approximate.x - 1,
                round->map->x + 1
    );

    if (CheckCarsCollision(round)) {
        round->player->collider.approximate.x = lastX;
        return;
    }

    auto it = CheckPointsCollision(round->player, round->points);
    if (it != round->points.end()) {
        round->points.erase(it);
        round->score++;
    }
}

void RoundMoveRight(Round *round) {
    if (round == nullptr) return;

    int lastX = round->player->collider.approximate.x;

    round->player->collider.approximate.x = std::min(
                round->player->collider.approximate.x + 1,
                round->map->x + round->map->w - round->player->collider.approximate.w - 1
    );

    if (CheckCarsCollision(round)) {
        round->player->collider.approximate.x = lastX;
        return;
    }

    auto it = CheckPointsCollision(round->player, round->points);
    if (it != round->points.end()) {
        round->points.erase(it);
        round->score++;
    }
}


void RoundMoveUp(Round *round) {
    if (round == nullptr) return;

    int lastY = round->player->collider.approximate.y;

    round->player->collider.approximate.y = std::max(
                round->player->collider.approximate.y - 1,
                round->map->y
    );

    if (CheckCarsCollision(round)) {
        round->player->collider.approximate.y = lastY;
        return;
    }

    auto it = CheckPointsCollision(round->player, round->points);
    if (it != round->points.end()) {
        round->points.erase(it);
        round->score++;
    }
}

void RoundMoveDown(Round *round) {
    if (round == nullptr) return;

    int lastY = round->player->collider.approximate.y;

    round->player->collider.approximate.y = std::min(
                round->player->collider.approximate.y + 1,
                round->map->h + round->map->y - round->player->collider.approximate.h
    );

    if (CheckCarsCollision(round)) {
        round->player->collider.approximate.y = lastY;
        return;
    }

    auto it = CheckPointsCollision(round->player, round->points);
    if (it != round->points.end()) {
        round->points.erase(it);
        round->score++;
    }
}
