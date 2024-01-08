#ifndef SPRITEDRAW_H
#define SPRITEDRAW_H

#include <vector>
#include <string>

struct Sprite {
    int w;
    int h;
    std::vector<std::string> data;
};

enum Repeats {
    REPEAT_NO,
    REPEAT_X,
    REPEAT_Y,
    REPEAT_ALL,
};

void SpriteDraw(const Sprite &sprite, int x, int y, int w, int h, int scaleX, int scaleY, Repeats repeat);


#endif // SPRITEDRAW_H
