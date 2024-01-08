#include <ncurses.h>

#include "Menu.h"

void MenuDraw(Menu *menu, int w, int h) {
    if (menu == nullptr) return;

    for (int i = 0; i < OPTIONS_SIZE; ++i) {
        move(h / 2 + (i - OPTIONS_SIZE / 2), w / 2);
        if (i == menu->activeOption) {
            printw("> ");
        }
        printw("%s", MenuOptions[i].c_str());
    }
}
