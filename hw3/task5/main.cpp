#include "sum.h"

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

    printf("sum = %lf\n", sum(x, eps));

    return 0;
}
