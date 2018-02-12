#include <iostream>
#include "../include/Game.hpp"
#include "../include/Definitions.hpp"

int main(char* args)
{
    game::Game(game::Constants::WINDOW_WIDTH, game::Constants::WINDOW_HEIGHT, "SFML Tutorial");

    return EXIT_SUCCESS;
}