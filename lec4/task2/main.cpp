#include <stdio.h>

// Заполнить матрицу 7 на 8 по правилу:
// на главной диагонали 0, над главной диагональю 1, под главной диагональю -1

int main()
{
    constexpr int H = 7;
    constexpr int W = 8;
    int mat[H][W] = {};

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i < j) {
                mat[i][j] = 1;
            } else if (i > j) {
                mat[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
