#include <math.h>
#include <stdio.h>

using namespace std;

int main()
{
    double x;
    scanf("%lf", &x);

    double p = (2 * cos(x - M_PI / 6) + sqrt(2)) * exp(3 * x);
    double q = 1 / (2 * log(x)) + pow(sin(pow(x, 2)), 2);
    double y = p / q;

    printf("%lf\n", y);

    return 0;
}
