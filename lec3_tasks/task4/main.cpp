#include <stdio.h>

int main()
{
    unsigned long long n;

    printf("enter n\n");
    scanf("%llu", &n);

    unsigned long long sum = 1;

    for (unsigned long i = 2; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    if (sum == n) {
        printf("ok\n");
        return 0;
    }

    printf("not ok\n");
    return 0;
}
