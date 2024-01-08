#ifndef SPRITES_H
#define SPRITES_H

#include "Draw/SpriteDraw.h"

enum COLORS {
    COLORS_YELLOW_BLACK = 1,
    COLORS_RED_BLACK,
    COLORS_MAGENTA_BLACK,
    COLORS_CYAN_BLACK,
};

const Sprite MapSprite = Sprite{
        .w = 13,
        .h = 5,
        .data = {
            "             ",
            "#           #",
            "#           #",
            "#           #",
            "             ",
        },
};

const Sprite CarSprite = Sprite{
        .w = 3,
        .h = 4,
        .data = {
            " ^ ",
            "***",
            " * ",
            "/ \\",
        },
};

const Sprite PointSprite = Sprite{
        .w = 3,
        .h = 3,
        .data = {
            " ^ ",
            "<+>",
            " v ",
        },
};

const Sprite DebugChar = Sprite{
        .w = 1,
        .h = 1,
        .data = {
            "_",
        },
};

#endif // SPRITES_H
