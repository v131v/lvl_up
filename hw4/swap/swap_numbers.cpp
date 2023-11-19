#include "swap_numbers.h"

void swapNums(int *ar, int size) {

    int mxIdx = 0;
    int lastNegIdx = 0;

    for (int i = 1; i < size; i++) {
        if (ar[mxIdx] < ar[i]) {
            mxIdx = i;
        }

        if (ar[i] < 0) {
            lastNegIdx = i;
        }
    }

    // printf("max: %d; last negative: %d\n", ar[mxIdx], ar[lastNegIdx]);

    // swap
    ar[mxIdx] += ar[lastNegIdx];
    ar[lastNegIdx] = ar[mxIdx] - ar[lastNegIdx];
    ar[mxIdx] -= ar[lastNegIdx];
}
