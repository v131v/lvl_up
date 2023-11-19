#include "f.h"

#include <stdio.h>

int main()
{
    long double x;
    scanf("%LF", &x);

    printf("%LF\n", f(x));

    return 0;
}
