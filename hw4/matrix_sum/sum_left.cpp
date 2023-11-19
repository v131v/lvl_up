#include "sum_left.h"

int sumLeft(int *matrix, int h, int w) {

    int sum = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if ((w - j - 1) > i) {
                sum += *(matrix + i * w + j);
            }
        }
    }

    return sum;
}
