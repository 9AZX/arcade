/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SfmlModule
*/

#include "SfmlModule.hpp"
#include <iostream>

SfmlModule::SfmlModule()
{
    this->_window = std::make_unique<sf::Window>(
        sf::VideoMode(SFML_WINDOW_HEIGHT, SFML_WINDOW_WIDTH),
        SFML_WINDOW_NAME);
    this->_window->setFramerateLimit(SFML_WINDOW_FRAMERATE);
    while (this->_window->isOpen()) {
        sf::Event event;
        while (this->_window->pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                this->_window->close();
            }
        }
    }
}

SfmlModule::~SfmlModule()
{
}

std::vector<enum gameInputs> SfmlModule::getInputs()
{
    std::vector<enum gameInputs> mdr;
    return mdr;
}

void SfmlModule::displayEntity(AEntity&)
{
}
void SfmlModule::displayMap(GameMap map)
{
}
void SfmlModule::renderTextEntity(AEntity&) const
{
}
void SfmlModule::renderGameEntity(AEntity&) const
{
}

void SfmlModule::matchInputs(std::vector<enum gameInputs>& inputs, sf::Keyboard::Key key)
{
    (void)inputs;
    (void)key;
}

void SfmlModule::destructor()
{
    delete this;
}