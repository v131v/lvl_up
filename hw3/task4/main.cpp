#include "print_binary.h"

#include <stdio.h>

int main()
{
    long long n;

    printf("enter integer number:\n");
    scanf("%lld", &n);

    printBinary(n);

    return 0;
}
