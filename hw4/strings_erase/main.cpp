#include <stdio.h>

int main()
{
    constexpr int length = 255;
    char str[length] = {};

    printf("enter string:\n");
    gets(str);

    int curIdx = 0;
    int outputIdx = 0;

    printf("result:\n");
    while (str[outputIdx] != '\0') {

        while (str[curIdx] != ' ' && str[curIdx] != '\0') {
            curIdx++;
        }

        if ((curIdx - outputIdx) % 2 == 0) {

            char lst = str[curIdx];
            str[curIdx] = '\0';
            printf("%s ", str + outputIdx);
            str[curIdx] = lst;
        }

        if (str[curIdx] == '\0') {
            break;
        }

        curIdx++;
        outputIdx = curIdx;
    }
    printf("\n");

    return 0;
}
