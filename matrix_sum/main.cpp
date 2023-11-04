#include <stdio.h>
#include <time.h>
#include <random>

int main()
{
    srand(time(0));

    constexpr int h = 6;
    constexpr int w = 5;

    int matrix[h][w] = {};

    const int maxValue = 10;

    printf("matrix:\n");
    for (int i = 0; i < h; i++) {

        for (int j = 0; j < w; j++) {

            matrix[i][j] = rand() % maxValue;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int sum = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if ((w - j - 1) > i) {
                sum += matrix[i][j];
            }
        }
    }

    printf("sum = %d\n", sum);

    return 0;
}
