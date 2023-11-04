#include <stdio.h>

int main()
{
    constexpr int size = 10;
    int ar[size] = {};

    printf("enter 40 numbers:\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &ar[i]);
    }

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
