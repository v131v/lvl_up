#include "../sum.h"

#include <gtest/gtest.h>
#include <stdlib.h>
#include <math.h>

const double eps = 1e-5;

TEST(SUM, 0_5) {
    const double x = 0.5;
    const double ans = 0.523598;

    ASSERT_LE(abs(sum(x, eps) - ans), eps);
}

TEST(SUM, 0_05001) {
    const double x = 0.05001;
    const double ans = 0.050031;

    ASSERT_LE(abs(sum(x, eps) - ans), eps);
}
