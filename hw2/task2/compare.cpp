#include <math.h>

const char* compare(double r, double a, double d) {

    double circle = M_PI * pow(r, 2);
    double triangle = pow(a, 2) * sqrt(3) / 4;
    double square = pow(d, 2);

    return (circle > triangle && circle > square ? "circle" : (triangle > square ? "triangle" : "square"));
}
