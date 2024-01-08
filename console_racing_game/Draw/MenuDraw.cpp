#include <ncurses.h>

#include "Menu.h"

void MenuDraw(Menu *menu, int w, int h) {
    if (menu == nullptr) return;
    int x,y;

    for (int i = 0; i < OPTIONS_SIZE; ++i) {
        x = w / 2;
        y = h / 2 + (i - OPTIONS_SIZE / 2);

        if (i == menu->activeOption) {
            move(y, x);
            addch('>');
            x++;

            move(y, x);
            addch(' ');
            x++;
        }

        for (size_t j = 0; j < MenuOptions[i].length(); j++) {
            move(y, x);
            addch(MenuOptions[i][j]);
            x++;
        }
    }
}
