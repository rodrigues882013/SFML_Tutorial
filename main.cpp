#include <iostream>
#include "header/Game.hpp"
#include "header/Definitions.hpp"

int main(char* args)
{
    game::Game(game::Constants::WINDOW_WIDTH, game::Constants::WINDOW_HEIGHT, "SFML Tutorial");

    return EXIT_SUCCESS;
}