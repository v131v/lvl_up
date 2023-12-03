#include "swap_matrix.h"

#include <stdio.h>
#include <time.h>
#include <random>

void fillMatrix(int size, int* mat, int maxValue) {

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            mat[i * size + j] = rand() % maxValue;
        }
    }
}

void printMatrix(int size, int* mat) {

    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            printf("%2d ", mat[i * size + j]);
        }
        printf("\n");
    }
}

int main()
{
    srand(time(0));

    constexpr int size = 7;

    const int maxValue = 10;
    int matrix[size][size] = {};

    fillMatrix(size, &matrix[0][0], maxValue);

    printf("matrix:\n");
    printMatrix(size, &matrix[0][0]);
    printf("\n");

    int k;

    printf("enter k-th row (0-indexed):\n");
    scanf("%d", &k);

    if (k >= size) {
        printf("k out of range (shuold be < %d)\n", size);
        return 0;
    }

    swapMatrix(size, &matrix[0][0], k);

    printf("result:\n");
    printMatrix(size, &matrix[0][0]);
    printf("\n");
    return 0;
}
