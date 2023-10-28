#include <stdio.h>

int main()
{
    unsigned long long n;

    printf("enter natural number:\n");
    scanf("%llu", &n);

    unsigned long long last = n % 10llu;
    unsigned long long first = n;
    unsigned long long pw = 1;

    while (first >= 10llu) {
        first /= 10llu;
        pw *= 10llu;
    }

    n += first - last;
    n -= (first - last) * pw;

    printf("%llu\n", n);

    return 0;
}
