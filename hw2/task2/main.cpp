#include <stdio.h>
#include <math.h>

int main()
{
    double r;
    double a;
    double d;
    scanf("%lf %lf %lf", &r, &a, &d);

    double circle = M_PI * pow(r, 2);
    double triangle = pow(a, 2) * sqrt(3) / 4;
    double square = pow(d, 2);

    printf(circle > triangle && circle > square ? "circle" : (triangle > square ? "triangle" : "square");
    printf("\n");

    return 0;
}
