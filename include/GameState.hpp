#pragma once

#include "State.hpp"
#include "Game.hpp"

namespace game
{
    class GameState : public State
    {
    public:

        GameState(GameDataRef data);

        ~GameState();

        void init();

        void handle_input();

        void update(float dt);

        void draw(float dt);


    private:
        GameDataRef _data;
        sf::Sprite _background;
        sf::Sprite _pause_button;

        int turn;
        int game_state;


        void pause();

        void resume();
    };
}