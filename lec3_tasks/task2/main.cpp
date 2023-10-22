#include <math.h>
#include <stdio.h>

// Вывести сумму ряда -1^(n + 1) * (x-1)^n / (n-1)! с точностью eps = 10^-4, x [0; 2]

int main()
{
    const double eps = 1e-4;
    double x;

    scanf("%lf", &x);

    if (x > 2 || x < 0) {
        printf("invalid value of x (must be [0; 2])");
        return 0;
    }

    double sign = 1;
    double p = x - 1;
    double q = 1;

    double add = sign * p / q;
    double sum = 0;

    for (unsigned long long i = 1; fabs(add) > eps; i++) {
        sum += add;
        sign *= -1;
        p *= x - 1;
        q *= i;
        add = sign * p / q;
    }

    printf("%lf\n", sum);

    return 0;
}
