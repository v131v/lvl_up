#include "lowestCommonDivisor.h"

#include <stdio.h>

int main()
{
    unsigned long long a;
    unsigned long long b;
    unsigned long long c;

    printf("enter 3 natural numbers:\n");
    scanf("%llu %llu %llu", &a, &b, &c);

    printf("lower common divisor: %llu\n", lowestCommonDivisor(a, b, c));

    return 0;
}
