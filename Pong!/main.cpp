#include "Game.hpp"



int main()
{
    vg::Game game;
    game.setResolution(600, 800);
    game.setCaption("pong");
    game.setup();
    game.runGame();

    return 0;
}