#include <stdio.h>
#include <string.h>

// Дана строка символов. Определить, является ли она палиндромом.

int main()
{
    constexpr int length = 255;
    char str[length] = {};

    gets(str);

    int i = 0;
    int j = strlen(str) - 1;

    while (j > i) {
        if (str[i] != str[j]) {
            printf("not a palindrome\n");
            return 0;
        }
        i++;
        j--;
    }

    printf("palindrome\n");

    return 0;
}
