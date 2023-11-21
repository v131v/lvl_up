/*
Задача 5.
Алгоритм A*.
Дана матрица bool. Матрица представляет собой лабиринт.
True — можно пройти.
False — нельзя пройти.

Дана начальная точка и точка выхода из лабиринта.
Найти минимальное число шагов до выхода из лабиринта.
int find(bool* mass, int x, int y, Point start, Point exit);
 */

#include <gtest/gtest.h>
#include <math.h>
#include <stdlib.h>

struct Point{
    int i;
    int j;
};

void swap(Point *a, Point *b) {
    Point tmp = *a;
    *a = *b;
    *b = tmp;
}

int g(Point cur, Point exit) {
    return fabs(cur.i - exit.i) + fabs(cur.j - exit.j);
}

void freeAr(Point *q) {
    delete[] q;
}

void freeMatrix(bool **matrix, int h) {
    for (int i = 0; i < h; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void freeMatrix(int **matrix, int h) {
    for (int i = 0; i < h; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

int find(bool *mass, int w, int h, Point start, Point exit) {

    if (start.i == exit.i && start.j == exit.j) return 0;

    if (w == 0 || h == 0) return -1;

    int qsize = 1;
    Point *q = new Point[w * h];
    q[0] = {start};

    bool **used = new bool*[h];
    for (int i = 0; i < h; ++i) used[i] = new bool[w];

    int **d = new int*[h];
    for (int i = 0; i < h; ++i) d[i] = new int[w];

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            d[i][j] = -1;
            used[i][j] = !(*(mass + i * h + j));
        }
    }

    d[start.i][start.j] = 0;

    while (qsize > 0) {
        int curIdx = 0;
        Point curPoint = q[curIdx];

        for (int i = 1; i < qsize; ++i) {
            if (d[curPoint.i][curPoint.j] + g(curPoint, exit) > d[q[i].i][q[i].j] + g(q[i], exit)) {
                curIdx = i;
                curPoint = q[i];
            }
        }

        swap(&q[curIdx], &q[qsize - 1]);
        --qsize;

        if (curPoint.i == exit.i && curPoint.j == exit.j) {

            int ans = d[exit.i][exit.j];

            freeMatrix(d, h);
            freeMatrix(used, h);
            freeAr(q);

            return ans;
        }

        // down
        if (curPoint.i + 1 < h) {
            Point addP = Point{curPoint.i + 1, curPoint.j};

            if (d[addP.i][addP.j] == -1 || d[addP.i][addP.j] > d[curPoint.i][curPoint.j] + 1) {
                d[addP.i][addP.j] = d[curPoint.i][curPoint.j] + 1;
            }

            if (!used[addP.i][addP.j]) {
                q[qsize] = addP;
                qsize++;

                used[addP.i][addP.j] = true;
            }
        }

        // right
        if (curPoint.j + 1 < w && !used[curPoint.i][curPoint.j + 1]) {
            Point addP = Point{curPoint.i, curPoint.j + 1};

            if (d[addP.i][addP.j] == -1 || d[addP.i][addP.j] > d[curPoint.i][curPoint.j] + 1) {
                d[addP.i][addP.j] = d[curPoint.i][curPoint.j] + 1;
            }

            if (!used[addP.i][addP.j]) {
                q[qsize] = addP;
                qsize++;

                used[addP.i][addP.j] = true;
            }
        }

        // up
        if (curPoint.i - 1 >= 0 && !used[curPoint.i - 1][curPoint.j]) {
            Point addP = Point{curPoint.i - 1, curPoint.j};

            if (d[addP.i][addP.j] == -1 || d[addP.i][addP.j] > d[curPoint.i][curPoint.j] + 1) {
                d[addP.i][addP.j] = d[curPoint.i][curPoint.j] + 1;
            }

            if (!used[addP.i][addP.j]) {
                q[qsize] = addP;
                qsize++;

                used[addP.i][addP.j] = true;
            }
        }

        // left
        if (curPoint.j - 1 >= 0 && !used[curPoint.i][curPoint.j - 1]) {
            Point addP = Point{curPoint.i, curPoint.j - 1};

            if (d[addP.i][addP.j] == -1 || d[addP.i][addP.j] > d[curPoint.i][curPoint.j] + 1) {
                d[addP.i][addP.j] = d[curPoint.i][curPoint.j] + 1;
            }

            if (!used[addP.i][addP.j]) {
                q[qsize] = addP;
                qsize++;

                used[addP.i][addP.j] = true;
            }
        }
    }

    freeMatrix(d, h);
    freeMatrix(used, h);
    freeAr(q);

    return -1;
}

TEST(ASTAR, CASE1) {
    constexpr int h = 5;
    constexpr int w = 5;

    bool *map = new bool[h * w]{
        1, 1, 1, 0, 1,
        1, 0, 0, 1, 1,
        1, 1, 0, 1, 1,
        1, 0, 0, 1, 1,
        1, 1, 1, 1, 1,
    };

    Point start = Point{0, 0};
    Point exit = Point{4, 4};

    ASSERT_EQ(find(map, h, w, start, exit), 8);

    delete[] map;
}

TEST(ASTAR, CASE2) {
    constexpr int h = 5;
    constexpr int w = 5;

    bool *map = new bool[h * w]{
        1, 1, 1, 0, 1,
        1, 0, 0, 1, 1,
        1, 1, 0, 1, 1,
        1, 0, 0, 1, 1,
        1, 1, 1, 0, 1,
    };

    Point start = Point{0, 0};
    Point exit = Point{4, 4};

    ASSERT_EQ(find(map, h, w, start, exit), -1);

    delete[] map;
}

TEST(ASTAR, CASE3) {
    constexpr int h = 5;
    constexpr int w = 5;

    bool *map = new bool[h * w]{
        1, 1, 1, 0, 1,
        0, 1, 0, 1, 1,
        1, 1, 1, 1, 1,
        0, 1, 0, 0, 1,
        1, 1, 1, 0, 1,
    };

    Point start = Point{0, 0};
    Point exit = Point{4, 4};

    ASSERT_EQ(find(map, h, w, start, exit), 8);

    delete[] map;
}

TEST(ASTAR, CASE4) {
    constexpr int h = 0;
    constexpr int w = 0;

    bool *map = new bool[h * w]{};

    Point start = Point{0, 0};
    Point exit = Point{0, 0};

    ASSERT_EQ(find(map, h, w, start, exit), 0);

    delete[] map;
}

TEST(ASTAR, CASE5) {
    constexpr int h = 0;
    constexpr int w = 0;

    bool *map = new bool[h * w]{};

    Point start = Point{0, 0};
    Point exit = Point{1, 1};

    ASSERT_EQ(find(map, h, w, start, exit), -1);

    delete[] map;
}

TEST(ASTAR, CASE6) {
    constexpr int h = 2;
    constexpr int w = 2;

    bool *map = new bool[h * w]{
        1, 0,
        0, 1,
    };

    Point start = Point{0, 0};
    Point exit = Point{1, 1};

    ASSERT_EQ(find(map, h, w, start, exit), -1);

    delete[] map;
}

TEST(ASTAR, CASE7) {
    constexpr int h = 5;
    constexpr int w = 5;

    bool *map = new bool[h * w]{
        1, 1, 1, 1, 0,
        0, 0, 0, 1, 1,
        1, 1, 1, 1, 0,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
    };

    Point start = Point{0, 0};
    Point exit = Point{4, 4};

    ASSERT_EQ(find(map, h, w, start, exit), 14);

    delete[] map;
}

TEST(ASTAR, CASE8) {
    constexpr int h = 5;
    constexpr int w = 5;

    bool *map = new bool[h * w]{
        1, 0, 1, 1, 1,
        1, 0, 1, 0, 1,
        1, 0, 1, 0, 1,
        1, 0, 0, 0, 1,
        1, 1, 1, 1, 1,
    };

    Point start = Point{0, 0};
    Point exit = Point{2, 2};

    ASSERT_EQ(find(map, h, w, start, exit), 16);

    delete[] map;
}
