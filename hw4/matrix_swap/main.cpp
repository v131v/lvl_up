#include <stdio.h>
#include <time.h>
#include <random>

int main()
{
    srand(time(0));

    constexpr int size = 7;

    const int maxValue = 10;
    int matrix[size][size] = {};

    printf("matrix:\n");
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            matrix[i][j] = rand() % maxValue;
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int k;

    printf("enter k-th row (0-indexed):\n");
    scanf("%d", &k);

    if (k >= size) {
        printf("k out of range (shuold be < %d)\n", size);
        return 0;
    }

    for (int i = 0; i < size; i++) {

        if (i == k) continue;

        // swap
        matrix[i][k] += matrix[k][i];
        matrix[k][i] = matrix[i][k] - matrix[k][i];
        matrix[i][k] -= matrix[k][i];
    }

    printf("result:\n");
    for (int i = 0; i < size; i++) {

        for (int j = 0; j < size; j++) {

            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
