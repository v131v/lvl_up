#include <ncurses.h>

#include "Game.h"
#include "MenuDraw.h"
#include "RoundDraw.h"
#include "StatisticsDraw.h"

void drawBackground(Game *game) {
    if (game == nullptr) return;

    for (int i = 0; i < game->h; ++i) {
        for (int j = 0; j < game->w; ++j) {
            move(i, j);
            addch(' ');
        }
    }
}

void Draw(Game *game) {
    if (game == nullptr) return;
    drawBackground(game);

    switch (game->status) {
    case STATUS_MENU:
        MenuDraw(game->menu, game->w, game->h);
        break;
    case STATUS_ROUND:
        RoundDraw(game->round, game->w, game->h);
        break;
    case STATUS_ROUND_END:
        RoundDraw(game->round, game->w, game->h);
        break;
    case STATUS_STATISTICS:
        StatisticsDraw(game->statistics, game->w, game->h);
        break;
    }

    refresh();
}
