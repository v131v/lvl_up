#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double r;
    double a;
    double d;
    cin >> r >> a >> d;

    double circle = M_PI * pow(r, 2);
    double triangle = pow(a, 2) * sqrt(3) / 4;
    double square = pow(d, 2);

    cout << (circle > triangle && circle > square ? "circle" : (triangle > square ? "triangle" : "square")) << '\n';

    return 0;
}
