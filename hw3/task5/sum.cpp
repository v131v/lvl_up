#include "sum.h"

#include <math.h>

double sum(double x, double precision) {

    double add = x;
    double sum = add;

    for (unsigned long long i = 1; fabs(add) > precision; i++) {
        add *= x * x;
        add *= ((double)((2 * i - 1) * (2 * i - 1)) / (double)((2 * i) * (2 * i + 1)));
        sum += add;
    }

    return sum;
}
