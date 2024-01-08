#include <ncurses.h>

#include "Round.h"
#include "Sprites.h"
#include "Draw/SpriteDraw.h"

void RoundDraw(Round *round, int w, int h){
    attron(COLOR_PAIR(COLORS_YELLOW_BLACK));
    int mapY = ((-round->map->y) % MapSprite.h) - MapSprite.h;
    SpriteDraw(
                round->map->sprite,
                round->map->x,
                mapY,
                round->map->w,
                round->map->h - mapY,
                1, 1, REPEAT_Y);
    attroff(COLOR_PAIR(COLORS_YELLOW_BLACK));

    attron(COLOR_PAIR(COLORS_CYAN_BLACK));
    SpriteDraw(
                round->player->sprite,
                round->player->collider.approximate.x - round->camX,
                round->player->collider.approximate.y - round->camY,
                round->player->collider.approximate.w,
                round->player->collider.approximate.h,
                1, 1, REPEAT_NO);
    attroff(COLOR_PAIR(COLORS_CYAN_BLACK));

    attron(COLOR_PAIR(COLORS_RED_BLACK));
    for (const auto &car : round->cars) {
        if (car->collider.approximate.y + car->collider.approximate.h < round->camY) {
            break;
        }

        SpriteDraw(
                    car->sprite,
                    car->collider.approximate.x - round->camX,
                    car->collider.approximate.y - round->camY,
                    car->collider.approximate.w,
                    car->collider.approximate.h,
                    1, 1, REPEAT_NO);
    }
    attroff(COLOR_PAIR(COLORS_RED_BLACK));

    attron(COLOR_PAIR(COLORS_MAGENTA_BLACK));
    for (const auto &point : round->points) {
        if (point->collider.approximate.y + point->collider.approximate.h < round->camY) {
            break;
        }

        SpriteDraw(
                    point->sprite,
                    point->collider.approximate.x - round->camX,
                    point->collider.approximate.y - round->camY,
                    point->collider.approximate.w,
                    point->collider.approximate.h,
                    1, 1, REPEAT_NO);
    }
    attroff(COLOR_PAIR(COLORS_MAGENTA_BLACK));

    move(0, 0);
    printw("Score:         %d", round->score);
    move(1, 0);
    printw("Passed meters: %d", round->passedMeters);
}
