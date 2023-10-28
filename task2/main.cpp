#include <stdio.h>

int main()
{
    unsigned long long a;
    unsigned long long b;
    unsigned long long c;

    printf("enter 3 natural numbers:\n");
    scanf("%llu %llu %llu", &a, &b, &c);

    unsigned long long min = (a > b && a > c ? a : (b > c ? b : c));

    unsigned long long d = 1;

    for (unsigned long long i = 2; i*i <= min; i++) {
        if (a % i == 0 && b % i == 0 && c % i == 0) {
            d = i;
            break;
        }
    }

    printf("lower common divisor: %llu\n", d);

    return 0;
}
