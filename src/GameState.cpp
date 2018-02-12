#include <iostream>
#include "../include/GameState.hpp"
#include "../include/Definitions.hpp"

namespace game
{

    GameState::GameState(GameDataRef data) {
        this->_data = data;
    }

    GameState::~GameState() {

    }

    void GameState::init() {
        game_state = Constants::STATE_PLAYING;
        turn = Constants::PLAYER_PIECE;

        this->_data->assets.load_texture("Pause Button", Constants::PAUSE_BUTTON);
        _background.setTexture(this->_data->assets.get_texture("Background"));
        _pause_button.setTexture(this->_data->assets.get_texture("Pause Button"));
        _pause_button.setPosition(this->_data->window.getSize().x - _pause_button.getLocalBounds().width,
                                  this->_data->window.getPosition().y);
    }

    void GameState::handle_input() {
        sf::Event event;

        while(this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }

            if(this->_data->inputs.is_sprite_clicked(this->_pause_button, sf::Mouse::Left, this->_data->window))
            {
                std::cout << "Pause The Game" << std::endl;
            }
        }
    }

    void GameState::update(float dt) {

    }

    void GameState::draw(float dt) {
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_pause_button);
        this->_data->window.display();
    }

    void GameState::pause() {

    }

    void GameState::resume() {

    }
}