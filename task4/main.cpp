#include <stdio.h>

int main()
{
    long long n;

    printf("enter integer number:\n");
    scanf("%lld", &n);

    bool curBit;
    unsigned long long mask = 1llu << (sizeof(long long) * __CHAR_BIT__ - 1ll);

    printf("binary format:\n");
    while (mask > 0ll) {
        curBit = n & mask;
        printf("%d", curBit);
        mask >>= 1;
    }
    printf("\n");

    return 0;
}
