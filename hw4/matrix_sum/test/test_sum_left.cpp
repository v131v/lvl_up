#include "../sum_left.h"

#include <gtest/gtest.h>

TEST(SUM_LEFT, ONE_BY_ONE) {
    constexpr int h = 1;
    constexpr int w = 1;
    int m[h][w] = {10};

    ASSERT_EQ(sumLeft(m[0], h, w), 0);
}

TEST(SUM_LEFT, HORIZONTAL) {
    constexpr int h = 2;
    constexpr int w = 4;
    int m[h][w] = {{1, 2, 3, 4}, {1, 2, 3, 4}};

    ASSERT_EQ(sumLeft(m[0], h, w), 9);
}

TEST(SUM_LEFT, ZERO_BY_ZERO) {
    constexpr int h = 0;
    constexpr int w = 0;
    int m[h][w] = {};

    ASSERT_EQ(sumLeft(m[0], h, w), 0);
}
