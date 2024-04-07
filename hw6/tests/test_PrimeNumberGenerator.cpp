#include "../PrimeNumberGenerator.h"

#include <gtest/gtest.h>

TEST(PrimeNumberGenerator, Init) {
    PrimeNumberGenerator gen(1e7);

    EXPECT_LE(gen.maxValue(), 1e7);
}

TEST(PrimeNumberGenerator, UpperBound_0) {
    PrimeNumberGenerator gen(1e7);

    EXPECT_EQ(gen.upperBound(0), 2);
}

TEST(PrimeNumberGenerator, UpperBound_1) {
    PrimeNumberGenerator gen(1e7);

    EXPECT_EQ(gen.upperBound(1), 2);
}

TEST(PrimeNumberGenerator, UpperBound_2) {
    PrimeNumberGenerator gen(1e7);

    EXPECT_EQ(gen.upperBound(2), 3);
}

TEST(PrimeNumberGenerator, UpperBound_7) {
    PrimeNumberGenerator gen(1e7);

    EXPECT_EQ(gen.upperBound(7), 11);
}
