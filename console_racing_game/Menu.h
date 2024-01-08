#ifndef MENU_H
#define MENU_H

#include <string>

constexpr int OPTIONS_SIZE = 3;
const std::string MenuOptions[OPTIONS_SIZE] = {"start", "statistics", "exit"};

struct Menu {
    int activeOption = 0;
};

Menu* CreateMenu();

#endif // MENU_H
