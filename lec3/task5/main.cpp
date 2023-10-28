#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

/* reads from keypress, doesn't echo */
int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}

int main()
{
    const unsigned long long w = 20;
    const unsigned long long h = 20;

    unsigned long long playerX = 1;
    unsigned long long playerY = 1;

    unsigned long long finishX = 18;
    unsigned long long finishY = 18;

    while (playerX != finishX || playerY != finishY) {

        system("clear");

        for (unsigned long long y = 0; y < h; ++y) {
            for (unsigned long long x = 0; x < w; ++x) {

                // Углы
                if ((x == 0 && y == 0) ||
                    (x == w - 1 && y == 0) ||
                    (x == 0 && y == h - 1) ||
                    (x == w - 1 && y == h - 1))
                {
                    printf("+");
                    continue;
                }

                // Горизонтальные стены
                if (y == 0 || y == h - 1) {
                    printf("-");
                    continue;
                }

                // Вертикальные стены
                if (x == 0 || x == w - 1) {
                    printf("|");
                    continue;
                }

                // Игрок
                if (y == playerY && x == playerX) {
                    printf("X");
                    continue;
                }

                // Финиш
                if (y == finishY && x == finishX) {
                    printf("O");
                    continue;
                }

                printf(" ");
            }
            printf("\n");
        }

        char op = getch();

        switch (op) {
        case 'w':
            if (playerY - 1 > 0) {
                playerY -= 1;
            }
            break;
        case 's':
            if (playerY + 1 < h - 1) {
                playerY += 1;
            }
            break;
        case 'a':
            if (playerX - 1 > 0) {
                playerX -= 1;
            }
            break;
        case 'd':
            if (playerX + 1 < w - 1) {
                playerX += 1;
            }
            break;
        }
    }
    return 0;
}
