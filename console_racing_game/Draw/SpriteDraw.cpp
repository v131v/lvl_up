#include <ncurses.h>

#include "SpriteDraw.h"

void oneCharDraw(char ch, int x, int y, int w, int h, int scaleX, int scaleY) {
    if (ch == ' ') return;

    int maxH, maxW;
    getmaxyx(stdscr, maxH, maxW);

    for (int i = 0; i < scaleX && i < w; i++) {
        for (int j = 0; j < scaleY && j < h; j++) {

            if (y+j >= 0 && x+i >= 0 && y+j < maxH && x+i < maxW) {
                move(y+j, x+i);
                addch(ch);
            }
        }
    }
}

void oneSpriteDraw(const Sprite &sprite, int x, int y, int w, int h, int scaleX, int scaleY) {

    for (int x1 = 0; x1 < sprite.w && x1 * scaleX < w; x1++) {
        for (int y1 = 0; y1 < sprite.h && y1 * scaleY < h; y1++) {
            oneCharDraw(sprite.data[y1][x1], x + x1 * scaleX, y + y1 * scaleY, w - x1 * scaleX, h - y1 * scaleY, scaleX, scaleY);
        }
    }
}

void SpriteDraw(const Sprite &sprite, int x, int y, int w, int h, int scaleX, int scaleY, Repeats repeat) {
    for (int x1 = 0; x1 < w; x1 += scaleX * sprite.w) {
        for (int y1 = 0; y1 < h; y1 += scaleY * sprite.h) {

            oneSpriteDraw(sprite, x1 + x, y1 + y, w - x1, h - y1, scaleX, scaleY);

            if (repeat == REPEAT_NO) return;
            if (repeat == REPEAT_X) break;
        }

        if (repeat == REPEAT_Y) break;
    }
}
