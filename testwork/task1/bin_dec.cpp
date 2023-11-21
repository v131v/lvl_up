/*
Задача 3.
Десятично-двоичное число, это такое число, которое состоит только из единиц и нулей.
Например 10 (десять) или 101 (сто один).
Дано число N. Найти минимальное число десятично-двоичных чисел, что бы сумма их равнялась N.

int find(int N);

Примеры:
32 = 11 + 11 + 10
34 = 11 + 11 + 11 + 1
429 = 111 + 111 + 101 + 101 + 1 + ...
10 = 10
0 = 0
 */

#include <gtest/gtest.h>
#include <math.h>

int find(int n) {

    // if (n == 0) return 1;

    int mxDigit = 1;

    while (n > 0) {
        mxDigit = fmax(mxDigit, n % 10);
        n /= 10;
    }

    return mxDigit;
}

TEST(BIN_DEC, CASE1) {
    int n = 32;

    ASSERT_EQ(find(n), 3);
}

TEST(BIN_DEC, CASE2) {
    int n = 34;

    ASSERT_EQ(find(n), 4);
}

TEST(BIN_DEC, CASE3) {
    int n = 429;

    ASSERT_EQ(find(n), 9);
}

TEST(BIN_DEC, CASE4) {
    int n = 0;

    ASSERT_EQ(find(n), 1);
}

TEST(BIN_DEC, CASE5) {
    int n = 100111010;

    ASSERT_EQ(find(n), 1);
}
