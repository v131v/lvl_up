#include "find.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fillAr(int *ar, int n, int maxValue) {
    for (int i = 0; i < n; ++i) {
        ar[i] = rand() % maxValue;
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
    constexpr int sizeA = 30;
    int a[sizeA] = {};

    constexpr int sizeB = 15;
    int b[sizeB] = {};

    const int maxValue = 10;

    fillAr(a, sizeA, maxValue);
    fillAr(b, sizeB, maxValue);

    printf("numbers in A array:\n");
    printAr(a, sizeA);

    printf("numbers in B array:\n");
    printAr(b, sizeB);

    printf("indexies:\n");

    int ans[sizeA] = {};

    const int ansLen = find(a, sizeA, b, sizeB, ans);

    printAr(ans, ansLen);

    return 0;
}
