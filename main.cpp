#include "headers/GameWindow.h"

int main()
{
    unsigned int X_Resolution = 512U;
    unsigned int Y_Resolution = 512U;
    unsigned int RGB_color [3] = {20U, 20U, 70U};
    const char * title = "Game Title";

    GameWindow game;

    while(game.IsRunning())
    {
        game.Updater();

        game.Renderer();
    }

    return 0;
}