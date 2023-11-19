#include "f.h"

#include <math.h>

long double f(long double x) {
    // x > 0; x != 1
    const long double p = (2 * cos(x - M_PI / 6) + sqrt(2)) * exp(3 * x);
    const long double q = 1 / (2 * log(x)) + pow(sin(pow(x, 2)), 2);
    const long double y = p / q;
    return y;
}
