#include "compare.h"

#include <stdio.h>
#include <math.h>

int main()
{
    double r;
    double a;
    double d;
    scanf("%lf %lf %lf", &r, &a, &d);

    printf("%s\n", compare(r, a, d));

    return 0;
}
