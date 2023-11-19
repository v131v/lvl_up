#include "../compare.h"

#include <gtest/gtest.h>
#include <string.h>

TEST(COMPARE, CIRCLE) {
    const double r = 2;
    const double a = 1;
    const double d = 1;

    ASSERT_EQ(strcmp(compare(r, a, d), "circle"), 0);
}

TEST(COMPARE, TRIANGLE) {
    const double r = 1;
    const double a = 3;
    const double d = 1;

    ASSERT_EQ(strcmp(compare(r, a, d), "triangle"), 0);
}

TEST(COMPARE, SQUARE) {
    const double r = 1;
    const double a = 1;
    const double d = 2;

    ASSERT_EQ(strcmp(compare(r, a, d), "square"), 0);
}
