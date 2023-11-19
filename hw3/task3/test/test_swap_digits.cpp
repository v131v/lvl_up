#include "../swap_digits.h"

#include <gtest/gtest.h>

TEST(SWAP_DIGITS, ONE_DIGIT) {
    const unsigned long long n = 1;
    const unsigned long long out = 1;

    ASSERT_EQ(swapDigits(n), out);
}

TEST(SWAP_DIGITS, 10) {
    const unsigned long long n = 10;
    const unsigned long long out = 1;

    ASSERT_EQ(swapDigits(n), out);
}

TEST(SWAP_DIGITS, 3608) {
    const unsigned long long n = 3608;
    const unsigned long long out = 8603;

    ASSERT_EQ(swapDigits(n), out);
}
