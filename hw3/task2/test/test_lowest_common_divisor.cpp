#include "../lowestCommonDivisor.h"

#include <gtest/gtest.h>

TEST(LCD, 3_DIVISOR) {
    const unsigned long long a = 6;
    const unsigned long long b = 15;
    const unsigned long long c = 27;

    ASSERT_EQ(lowestCommonDivisor(a, b, c), 3);
}

TEST(LCD, EQUAL_NUMBERS) {
    const unsigned long long a = 4;
    const unsigned long long b = 4;
    const unsigned long long c = 4;

    ASSERT_EQ(lowestCommonDivisor(a, b, c), 2);
}

TEST(LCD, NO_COMMON_DIVISOR) {
    const unsigned long long a = 3;
    const unsigned long long b = 5;
    const unsigned long long c = 7;

    ASSERT_EQ(lowestCommonDivisor(a, b, c), 1);
}
