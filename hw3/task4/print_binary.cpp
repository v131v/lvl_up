#include "print_binary.h"

#include <stdio.h>
#include <string.h>

void getBinary(long long n, char* str) {

    bool curBit;
    unsigned long long mask = 1llu << (sizeof(long long) * __CHAR_BIT__ - 1ll);

    printf("binary format:\n");
    while (mask > 0ll) {
        curBit = n & mask;
        if (curBit == 0) {
            strcat(str, "0");
        } else {
            strcat(str, "1");
        }
        // printf("%d", curBit);
        mask >>= 1;
    }
    // printf("\n");
}
