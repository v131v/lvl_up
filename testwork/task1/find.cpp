#include <gtest/gtest.h>

/*
Задача 1.
Данн массив чисел. Каждое число в массиве встречается по 2 раза, кроме одного.
Найти это одинокое число.

int find(int* mass, int size);

Примеры:
[2, 1, 1, 2, 3] → 3
 */

int find(int* mass, int size) {
    int x = 0;

    for (int i = 0; i < size; ++i) {
        x = x ^ mass[i];
    }

    return x;
}

TEST(FIND, TEST1) {
    constexpr int size = 5;
    int arr[size] = {1, 2, 3, 1, 2};

    ASSERT_EQ(find(arr, size), 3);
}

TEST(FIND, TEST2) {
    constexpr int size = 5;
    int arr[size] = {2, 1, 1, 4, 2};

    ASSERT_EQ(find(arr, size), 4);
}

TEST(FIND, TEST3) {
    constexpr int size = 1;
    int arr[size] = {2};

    ASSERT_EQ(find(arr, size), 2);
}
