#include <ncurses.h>
#include <thread>

#include "Controllers/GameController.h"
#include "Draw/GameDraw.h"


using namespace std;

void keyListener(Game *game) {
    constexpr char ESC_BUTTON = 27;
    constexpr char ENTER_BUTTON = '\n';
    int ch = getch();

    while (game->status != STATUS_EXIT) {
        switch (ch) {
        case 'a':
            MoveLeft(game);
            break;
        case 'd':
            MoveRight(game);
            break;
        case 'w':
            MoveUp(game);
            break;
        case 's':
            MoveDown(game);
            break;
        case ENTER_BUTTON:
            Enter(game);
            break;
        case ESC_BUTTON:
            game->status = STATUS_EXIT;
            return;
        default:
            break;
        }

        ch = getch();
    }
}

void drawLoop(Game *game) {
    while (game->status != STATUS_EXIT) {
        Draw(game);

        this_thread::sleep_for(std::chrono::milliseconds(1000/30));
    }
}

int main(int argc, char *argv[]) {
    Game *game = CreateGame();

    thread draw(drawLoop, game);
    this_thread::sleep_for(std::chrono::milliseconds(100));

    thread listener(keyListener, game);

    draw.join();
    listener.join();

    EndGame(game);

    return 0;
}
