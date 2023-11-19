#include "sum_left.h"

#include <stdio.h>
#include <time.h>
#include <random>

void fillMatrix(int h, int w, int *matrix, int from, int to) {

    for (int i = 0; i < h; i++) {

        for (int j = 0; j < w; j++) {

            *(matrix + i * w + j) = rand() % (to - from) + from;
        }
    }
}

void printMatrix(int h, int w, int *matrix) {

    for (int i = 0; i < h; i++) {

        for (int j = 0; j < w; j++) {

            printf("%d ", *(matrix + i * w + j));
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    srand(time(0));

    constexpr int h = 6;
    constexpr int w = 5;

    int matrix[h][w] = {};

    const int maxValue = 10;

    fillMatrix(h, w, matrix[0], 0, maxValue);

    printf("matrix:\n");
    printMatrix(h, w, matrix[0]);

    printf("sum = %d\n", sumLeft(matrix[0], h, w));

    return 0;
}
