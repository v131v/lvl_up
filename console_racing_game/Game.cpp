#include <ncurses.h>

#include "Game.h"
#include "Menu.h"
#include "Round.h"
#include "Sprites.h"

Game* CreateGame() {
    Game *game = new Game();

    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    timeout(50);

    start_color();
    init_pair(COLORS_YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLORS_RED_BLACK, COLOR_RED, COLOR_BLACK);
    init_pair(COLORS_MAGENTA_BLACK, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLORS_CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);

    getmaxyx(stdscr, game->h, game->w);
    game->menu = CreateMenu();

    return game;
}

void EndGame(Game *game) {
    if (game == nullptr) return;

    endwin();
    delete game->menu;
    delete game;
}

void ChangeStatus(Game *game) {
    if (game == nullptr) return;

    game->status = MenuOptionsStatuses[game->menu->activeOption];

    switch (game->status) {
    case STATUS_ROUND:
        game->round = CreateRound(game->w, game->h);
        game->round->isActive = true;
        RoundNextState(game->round);
        game->round->isActive = false;
        game->status = STATUS_ROUND_END;
        break;
    }
}
