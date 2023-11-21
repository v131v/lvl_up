/*
Задача 2.
Есть несколько детей, у каждого ребенка есть некоторое число конфет. Число конфет у детей задается массивом.
Так же есть некоторое число дополнительных конфет.
Требуется определить, если указанному ребенку отдать все дополнительные конфеты, то будет ли у него их максимальное количество.

bool find(int* mass, int size, int child, int count);

Примеры:
[1, 2, 5, 2, 1], дополнительные конфеты 3.
Результаты по детям: false, true, true, true, false

size >= 2
mass[i] >= 0

 */

#include <math.h>
#include <gtest/gtest.h>

bool find(int* mass, int size, int child, int count) {

    int mx = 0;

    for (int i = 0; i < size; ++i) {
        mx = fmax(mx, mass[i]);
    }

    return mass[child] + count >= mx;
}

TEST(CANDY, CASE1) {
    constexpr int size = 5;
    int arr[size] = {1, 2, 5, 2, 1};
    int child = 0;
    int count = 3;

    ASSERT_FALSE(find(arr, size, child, count));
}

TEST(CANDY, CASE2) {
    constexpr int size = 5;
    int arr[size] = {1, 2, 5, 2, 1};
    int child = 1;
    int count = 3;

    ASSERT_TRUE(find(arr, size, child, count));
}

TEST(CANDY, CASE3) {
    constexpr int size = 5;
    int arr[size] = {1, 2, 5, 2, 1};
    int child = 2;
    int count = 3;

    ASSERT_TRUE(find(arr, size, child, count));
}

TEST(CANDY, CASE4) {
    constexpr int size = 2;
    int arr[size] = {0, 0};
    int child = 0;
    int count = 0;

    ASSERT_TRUE(find(arr, size, child, count));
}

TEST(CANDY, CASE5) {
    constexpr int size = 2;
    int arr[size] = {0, 0};
    int child = 0;
    int count = -5;

    ASSERT_FALSE(find(arr, size, child, count));
}
