#include "Menu.h"

void MenuMoveDown(Menu *menu) {
    if (menu == nullptr) return;
    menu->activeOption = (menu->activeOption + 1 + OPTIONS_SIZE) % OPTIONS_SIZE;
}

void MenuMoveUp(Menu *menu) {
    if (menu == nullptr) return;
    menu->activeOption = (menu->activeOption - 1 + OPTIONS_SIZE) % OPTIONS_SIZE;
}
