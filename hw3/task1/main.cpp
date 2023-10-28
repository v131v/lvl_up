#include <math.h>
#include <stdio.h>

int main()
{
    unsigned long long n;

    printf("enter natural number:\n");
    scanf("%llu", &n);

    unsigned long long len = floor(log10(n)) + 1;

    printf("length of number: %llu\n", len);

    return 0;
}
