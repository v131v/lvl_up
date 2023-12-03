#include "print_binary.h"

#include <stdio.h>

int main()
{
    long long n;

    printf("enter integer number:\n");
    scanf("%lld", &n);

    constexpr int BINARY_MAX_LENGTH = 64;
    char str[BINARY_MAX_LENGTH] = "";

    getBinary(n, str);

    printf("%s\n", str);

    return 0;
}
