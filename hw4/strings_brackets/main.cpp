#include "is_valid_sequence.h"

#include <stdio.h>

int main()
{
    constexpr int len = 255;
    char str[len];

    printf("enter string:\n");
    gets(str);

    if (isValidSequence(str)) {
        printf("ok\n");
    } else {
        printf("invalid bracket sequence\n");
    }

    return 0;
}
