#include <math.h>
#include <stdio.h>

const double eps = 1e-5;

int main()
{
    double x;

    printf("enter rational number between 0.05 and 1:\n");
    scanf("%lf", &x);

    if (x <= 0.05 || x >= 1) {
        printf("invalid number\n");
        return 0;
    }

    double add = x;
    double sum = add;

    for (unsigned long long i = 1; fabs(add) > eps; i++) {
        add *= x * x;
        add *= ((double)((2 * i - 1) * (2 * i - 1)) / (double)((2 * i) * (2 * i + 1)));
        sum += add;
    }

    printf("sum = %lf\n", sum);

    return 0;
}
