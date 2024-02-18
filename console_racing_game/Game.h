#ifndef GAME_H
#define GAME_H

#include <map>

#include "Menu.h"
#include "Round.h"

enum Status {
    STATUS_MENU,
    STATUS_ROUND,
    STATUS_ROUND_END,
    STATUS_STATISTICS,
    STATUS_EXIT,
};

constexpr Status MenuOptionsStatuses[OPTIONS_SIZE] = {STATUS_ROUND, STATUS_STATISTICS, STATUS_EXIT};

struct Game {
    int w = 0;
    int h = 0;
    int status = STATUS_MENU;

    Menu *menu;
    Round *round;

    std::multimap<int, int> statistics;
};

Game* CreateGame();

void DestroyGame(Game *game);

void ChangeStatus(Game *game);

#endif // GAME_H
