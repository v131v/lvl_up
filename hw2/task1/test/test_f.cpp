#include "../f.h"

#include <gtest/gtest.h>
#include <math.h>

constexpr long double eps = 1e-6;

TEST(F, 1_TO_0)
{
    const long double input = 1;
    const long double expect = 0;

    ASSERT_LE(abs(f(input) - expect), eps);
}

TEST(F, 17_12_PI_TO_0)
{
    const long double input = 17 * M_PI / 12;
    const long double expect = 0;

    ASSERT_LE(abs(f(input) - expect), eps);
}

TEST(F, 11_12_PI_TO_0)
{
    const long double input = 11 * M_PI / 12;
    const long double expect = 0;

    ASSERT_LE(abs(f(input) - expect), eps);
}
