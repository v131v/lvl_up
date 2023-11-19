#include "../swap_numbers.h"

#include <gtest/gtest.h>

TEST(SUM, POW_MINUS1_N_MULTIPLY_N) {
    constexpr int size = 5;
    int ar[size] = {1, -2, 3, -4, 5};
    int expect[size] = {1, -2, 3, 5, -4};

    swapNums(ar, size);

    ASSERT_EQ(memcmp(ar, expect, size), 0);
}

TEST(SUM, SAME_POSITIVE_NUMBERS) {
    constexpr int size = 5;
    int ar[size] = {-5, 1, 1, 1, 1};
    int expect[size] = {1, -5, 1, 1, 1};

    swapNums(ar, size);

    ASSERT_EQ(memcmp(ar, expect, size), 0);
}

TEST(SUM, NO_NEGATIVE) {
    constexpr int size = 5;
    int ar[size] = {3, 3, 4, 1, 2};
    int expect[size] = {4, 3, 3, 1, 2};

    swapNums(ar, size);

    ASSERT_EQ(memcmp(ar, expect, size), 0);
}
