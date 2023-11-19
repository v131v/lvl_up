#include "swap_digits.h"

#include <stdio.h>

int main()
{
    unsigned long long n;

    printf("enter natural number:\n");
    scanf("%llu", &n);

    printf("%llu\n", swapDigits(n));

    return 0;
}
