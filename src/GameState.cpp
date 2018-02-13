#include <iostream>
#include <utility>
#include "../include/GameState.hpp"
#include "../include/Definitions.hpp"
#include "../include/PauseState.hpp"

namespace game
{

    GameState::GameState(GameDataRef data) {
        this->_data = std::move(data);
    }

    GameState::~GameState() {

    }

    void GameState::init() {
        game_state = Constants::STATE_PLAYING;
        turn = Constants::PLAYER_PIECE;

        load_texture();
        set_positions();
        init_grid_piece();
        init_grid_array();


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
                this->_data->machine.add_state(StateRef(new PauseState(_data)), false);
            }
        }
    }

    void GameState::update(float dt) {

    }

    void GameState::draw(float dt) {
        this->_data->window.clear();
        this->_data->window.draw(this->_background);
        this->_data->window.draw(this->_pause_button);
        this->_data->window.draw(this->_grid);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                this->_data->window.draw(this->_grid_pieces[i][j]);
            }
        }





        this->_data->window.display();
    }

    void GameState::pause() {

    }

    void GameState::resume() {

    }

    void GameState::init_grid_piece()
    {
        sf::Vector2u tempSprinteSize = this->_data->assets.get_texture("X Piece").getSize();

        for(int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                _grid_pieces[i][j].setTexture(this->_data->assets.get_texture("X Piece"));
                _grid_pieces[i][j].setPosition(_grid.getPosition().x + (tempSprinteSize.x * i) - 7,
                                               _grid.getPosition().y + (tempSprinteSize.y * j) - 7);

                _grid_pieces[i][j].setColor(sf::Color(255, 255, 255, 255));
            }
        }

    }

    void GameState::init_grid_array()
    {
        for(int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                grid_array[i][j] = Constants::EMPTY_PIECE;
            }
        }
    }

    void GameState::load_texture() {
        this->_data->assets.load_texture("Pause Button", Constants::PAUSE_BUTTON);
        this->_data->assets.load_texture("Grid", Constants::GRID_SPRITE_FILE_PATH);
        this->_data->assets.load_texture("X Piece", Constants::X_PIECE_FILEPATH);
        this->_data->assets.load_texture("O Piece", Constants::O_PIECE_FILEPATH);


        _background.setTexture(this->_data->assets.get_texture("Background"));
        _pause_button.setTexture(this->_data->assets.get_texture("Pause Button"));
        _grid.setTexture(this->_data->assets.get_texture("Grid"));
    }

    void GameState::set_positions() {

        _pause_button.setPosition(this->_data->window.getSize().x - _pause_button.getLocalBounds().width,
                                  this->_data->window.getPosition().y);

        _grid.setPosition((Constants::WINDOW_WIDTH/2) - (_grid.getGlobalBounds().width/2),
                          (Constants::WINDOW_HEIGHT/2) - (_grid.getGlobalBounds().height/2));
    }
}