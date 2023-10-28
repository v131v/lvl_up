#include <stdio.h>

int a;
int b;
int c;
int d;

int main()
{
    a=5, c=5;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    a=a+b-2;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    c=c+1, d=c-a+d;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    a=a*c, c=c-1;
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    a=a/10, c=c/2, b=b-1, d=d*(c+b+a);
    printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);

    return 0;
}
