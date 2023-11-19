#include "../find.h"

#include <gtest/gtest.h>

TEST(FIND, FIND1)
{
    constexpr int sizeA = 5;
    int a[sizeA] = {1, 2, 3, 4, 5};

    constexpr int sizeB = 5;
    int b[sizeB] = {1, 1, 2, 4, 4};

    int ans[sizeA] = {};

    const int sizeAns = find(a, sizeA, b, sizeB, ans);

    const int expectedAns[] = {2, 4};

    EXPECT_EQ(sizeAns, 2);

    EXPECT_EQ(memcmp(ans, expectedAns, sizeAns * sizeof(int)), 0);
}

TEST(FIND, FIND2)
{
    constexpr int sizeA = 0;
    int *a = nullptr;

    constexpr int sizeB = 0;
    int *b = nullptr;

    int ans[sizeA] = {};

    const int sizeAns = find(a, sizeA, b, sizeB, ans);

    const int expectedAns[0] = {};

    EXPECT_EQ(sizeAns, 0);

    EXPECT_EQ(memcmp(ans, expectedAns, sizeAns * sizeof(int)), 0);
}
