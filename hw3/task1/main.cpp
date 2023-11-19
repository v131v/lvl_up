#include "numlen.h"

#include <math.h>
#include <stdio.h>

int main()
{
    unsigned long long n;

    printf("enter natural number:\n");
    scanf("%llu", &n);

    printf("length of number: %llu\n", numlen(n));

    return 0;
}
