#include <ncurses.h>
#include <map>
#include <string>

void StatisticsDraw(std::multimap<int, int> stat, int w, int h) {
    std::string head = "Score | Meters passed";
    int x = (w - head.length()) / 2;
    int y = (h - stat.size()) / 2 - 1;
    move(y, x);
    printw("%s", head.c_str());

    for (auto row = stat.rbegin(); row != stat.rend(); row++) {
        y++;
        move(y, x);
        printw("%5d | %13d", row->first, row->second);
    }
}
