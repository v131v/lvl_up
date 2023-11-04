#include <stdio.h>

int main()
{
    constexpr int len = 255;
    char str[len];

    printf("enter string:\n");
    gets(str);

    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '(' && str[i] != ')') {
            printf("incorrect bracket '%c' at %d position\n", str[i], i);
            return 0;
        }

        if (str[i] == '(') {
            cnt++;
        }

        if (str[i] == ')') {
            cnt--;
        }

        if (cnt < 0) {
            break;
        }
    }

    if (cnt != 0) {
        printf("invalid bracket sequence\n");
    } else {
        printf("ok\n");
    }

    return 0;
}
