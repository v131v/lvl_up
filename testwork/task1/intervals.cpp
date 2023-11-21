/*
Задача 4.
Дан массив длиной N. Массив состоит из целых чисел. Дано целое число K.
Найти в этом массиве такой интервал, что бы сумма элементов в нем равнялась K.

struct Pair
{
 int first;
 int second;
}

Pair find(int* mass, int N, int k);

k = 5
1 2 3 4 -> {first: 1, second: 2}

k = 5
1 6 -> {first: -1}
 */

#include <gtest/gtest.h>

struct Pair
{
 int first;
 int second;
};

Pair find(int* mass, int n, int k) {

    for (int i = 0; i < n; i++) {

        int sum = 0;

        for (int j = i; j < n; ++j) {
            sum += mass[j];

            if (sum == k) {
                return Pair{i, j};
            }
        }
    }

    return Pair{-1, -1};
}

TEST(INTERVALS, CASE1) {
    constexpr int size = 4;
    int ar[size] = {1, 2, 3, 4};
    int k = 5;

    Pair pr = find(ar, size, k);
    ASSERT_EQ(pr.first, 1);
    ASSERT_EQ(pr.second, 2);
}

TEST(INTERVALS, CASE2) {
    constexpr int size = 2;
    int ar[size] = {1, 6};
    int k = 5;

    Pair pr = find(ar, size, k);
    ASSERT_EQ(pr.first, -1);
    ASSERT_EQ(pr.second, -1);
}

TEST(INTERVALS, CASE3) {
    constexpr int size = 5;
    int ar[size] = {1, 1, 1, 1, 1};
    int k = 3;

    Pair pr = find(ar, size, k);
    ASSERT_EQ(pr.first, 0);
    ASSERT_EQ(pr.second, 2);
}

TEST(INTERVALS, CASE4) {
    constexpr int size = 4;
    int ar[size] = {-2, 1, -2, -3};
    int k = -4;

    Pair pr = find(ar, size, k);
    ASSERT_EQ(pr.first, 1);
    ASSERT_EQ(pr.second, 3);
}

TEST(INTERVALS, CASE5) {
    constexpr int size = 0;
    int ar[size] = {};
    int k = 0;

    Pair pr = find(ar, size, k);
    ASSERT_EQ(pr.first, -1);
    ASSERT_EQ(pr.second, -1);
}

TEST(INTERVALS, CASE6) {
    constexpr int size = 1;
    int ar[size] = {0};
    int k = 0;

    Pair pr = find(ar, size, k);
    ASSERT_EQ(pr.first, 0);
    ASSERT_EQ(pr.second, 0);
}
