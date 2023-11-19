#include "swap_numbers.h"

#include <stdio.h>
#include <time.h>
#include <random>

void fillAr(int *ar, int n, int from, int to) {
    for (int i = 0; i < n; ++i) {
        ar[i] = rand() % (to - from) + from;
    }
}

void printAr(int *ar, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(0));

    constexpr int size = 40;
    int ar[size] = {};

    fillAr(ar, size, -50, 50);

    printf("numbers:\n");
    printAr(ar, size);

    swapNums(ar, size);

    printf("result:\n");
    printAr(ar, size);

    return 0;
}
