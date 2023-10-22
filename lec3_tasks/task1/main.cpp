#include <math.h>
#include <stdio.h>

// Вывести сумму ряда f(x) = 1/2 * x + 2/3 * x^2 + 3/4 * x^3 + 4/5 * x^4 + ... с точностью
// e = 10^-5

int main()
{
    double sum = 0;
    double x;

    scanf("%lf", &x);

    if (x >= 1 || x < 0) {
        printf("invalid value of x (must be [0; 1])");
        return 0;
    }

    const double eps = 1e-5;
    double add = 0.5 * x;

    for (unsigned long long i = 2; add > eps; i++) {
        sum += add;
        add = (double)i / (i+1) * pow(x, i);
    }

    printf("%lf\n", sum);

    return 0;
}
