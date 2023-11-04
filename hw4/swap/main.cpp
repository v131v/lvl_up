#include <stdio.h>
#include <time.h>
#include <random>

int main()
{
    srand(time(0));

    constexpr int size = 40;
    int ar[size] = {};

    printf("numbers:\n");
    for (int i = 0; i < size; i++) {
        ar[i] = rand() % 100 - 50;
        printf("%d ", ar[i]);
    }
    printf("\n");

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

    printf("max: %d; last negative: %d\n", ar[mxIdx], ar[lastNegIdx]);

    // swap
    ar[mxIdx] += ar[lastNegIdx];
    ar[lastNegIdx] = ar[mxIdx] - ar[lastNegIdx];
    ar[mxIdx] -= ar[lastNegIdx];

    printf("result:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n");

    return 0;
}
