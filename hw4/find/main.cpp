#include <stdio.h>
#include <time.h>
#include <random>

int main()
{
    constexpr int sizeA = 30;
    int a[sizeA] = {};

    constexpr int sizeB = 15;
    int b[sizeB] = {};

    const int maxValue = 10;

    printf("numbers in A array:\n");
    for (int i = 0; i < sizeA; i++) {

        a[i] = rand() % maxValue;
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("numbers in B array:\n");
    for (int i = 0; i < sizeB; i++) {

        b[i] = rand() % maxValue;
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("indexies:\n");
    for (int i = 0; i < sizeA; i++) {

        bool fg = true;
        for (int j = 0; j < sizeB; j++) {

            if (a[i] == b[j]) {
                fg = false;
                break;
            }
        }

        if (fg) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
