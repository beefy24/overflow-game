//Author: beefy24 (https://github.com/beefy24), 2025.

#include "input.h"
#include "game.cpp"

int main()
{
    //Initialize
    Game game;
    game.renderStartScreen();

    //Game loop
    while (!game.getWinState() && game.getCurrentInput() != EXIT_GAME)
    {  
        game.handleInput();
        game.updateGame();
        game.renderGameScreen();
    };

    return 0;
}
