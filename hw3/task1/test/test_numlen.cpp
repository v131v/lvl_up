#include "../numlen.h"

#include <gtest/gtest.h>

TEST(NUMLEN, 1_TO_1) {
    const unsigned long long input = 1;
    const unsigned long long output = 1;

    ASSERT_EQ(numlen(input), output);
}

TEST(NUMLEN, 9_TO_1) {
    const unsigned long long input = 9;
    const unsigned long long output = 1;

    ASSERT_EQ(numlen(input), output);
}

TEST(NUMLEN, 10_TO_2) {
    const unsigned long long input = 10;
    const unsigned long long output = 2;

    ASSERT_EQ(numlen(input), output);
}

TEST(NUMLEN, 100_TO_3) {
    const unsigned long long input = 100;
    const unsigned long long output = 3;

    ASSERT_EQ(numlen(input), output);
}
