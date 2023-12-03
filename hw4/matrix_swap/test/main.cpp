#include "../swap_matrix.h"

#include <gtest/gtest.h>

// Помощник для сравнения матриц
bool matricesAreEqual(int size, const int* matrix1, const int* matrix2) {
    for (int i = 0; i < size * size; ++i) {
        if (matrix1[i] != matrix2[i]) {
            return false;
        }
    }
    return true;
}

// Тесты для функции swapMatrix
TEST(SwapMatrixTest, BasicSwap) {
    const int size = 3;
    int matrix[size][size] = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};

    int expectedMatrix[size][size] = {{1, 4, 7},
                                      {2, 5, 6},
                                      {3, 8, 9}};

    swapMatrix(size, &matrix[0][0], 0);

    EXPECT_TRUE(matricesAreEqual(size, &matrix[0][0], &expectedMatrix[0][0]));
}

TEST(SwapMatrixTest, SwapWithZeroSize) {
    const int size = 0;
    int matrix[size][size] = {};

    // Ничего не должно произойти при попытке обмена в пустой матрице
    swapMatrix(size, &matrix[0][0], 0);

    // Проверяем, что матрица осталась пустой
    EXPECT_TRUE(matricesAreEqual(size, &matrix[0][0], nullptr));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
