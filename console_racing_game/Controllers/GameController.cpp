#include <thread>

#include "Game.h"
#include "MenuController.h"
#include "RoundController.h"

void MoveLeft(Game *game) {
    if (game == nullptr) return;

    switch (game->status) {
    case STATUS_MENU:
        MenuMoveUp(game->menu);
        break;
    case STATUS_ROUND:
        RoundMoveLeft(game->round);
        break;
    }
}

void MoveRight(Game *game) {
    if (game == nullptr) return;

    switch (game->status) {
    case STATUS_MENU:
        MenuMoveDown(game->menu);
        break;
    case STATUS_ROUND:
        RoundMoveRight(game->round);
        break;
    }
}

void MoveDown(Game *game) {
    if (game == nullptr) return;

    switch (game->status) {
    case STATUS_MENU:
        MenuMoveDown(game->menu);
        break;
    case STATUS_ROUND:
        RoundMoveDown(game->round);
        break;
    }
}

void MoveUp(Game *game) {
    if (game == nullptr) return;

    switch (game->status) {
    case STATUS_MENU:
        MenuMoveUp(game->menu);
        break;
    case STATUS_ROUND:
        RoundMoveUp(game->round);
        break;
    }
}

void Enter(Game *game) {
    if (game == nullptr) return;

    switch (game->status) {
    case STATUS_STATISTICS:
        game->status = STATUS_MENU;
        break;
    case STATUS_ROUND_END:
        game->status = STATUS_MENU;
        game->statistics.insert(std::make_pair(game->round->score, game->round->passedMeters));
        EndRound(game->round);
        break;
    case STATUS_MENU:
        std::thread changeStatus(ChangeStatus, game);
        changeStatus.detach();
        break;
    }
}
