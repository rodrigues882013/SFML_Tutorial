#include <sstream>
#include <iostream>
#include "header/Definitions.hpp"
#include "header/SplashState.hpp"

namespace game {

    SplashState::SplashState(GameDataRef data) {
        this->_data = data;
    }

    SplashState::~SplashState() {

    }

    void SplashState::draw(float dt)
    {
        this->_data->window.clear(sf::Color::Red);
        this->_data->window.draw(this->_background);
        this->_data->window.display();
    }

    void SplashState::pause() {

    }

    void SplashState::resume()
    {

    }


    void SplashState::init()
    {
        this->_data->assets.load_texture( "splash_state_background", Constants::SPLASH_SCENE_BACKGROUND_FILEPATH);
        _background.setTexture(this->_data->assets.get_texture("splash_state_background"));
    }

    void SplashState::handle_input()
    {
        sf::Event event;

        while(this->_data->window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
            {
                this->_data->window.close();
            }
        }
    }

    void SplashState::update(float dt)
    {
        if(this->_clock.getElapsedTime().asSeconds() > Constants::SPLASH_STATE_SHOW_TIME )
        {
            // Switch to main menu
            std::cout << "Go to main menu" << std::endl;
        }
    }

}
