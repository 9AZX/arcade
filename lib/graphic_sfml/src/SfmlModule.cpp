/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SfmlModule
*/

#include "SfmlModule.hpp"

SfmlModule::SfmlModule() : _window(sf::VideoMode(650, 700), "SFML - Pacman")
{
}

SfmlModule::~SfmlModule()
{
}

// sf::RenderWindow &SfmlModule::getWindow()
// {
// 	return this->_window;
// }

void SfmlModule::initScreen()
{
	std::cout << "init screen" << std::endl;
}

void SfmlModule::drawScreen()
{
	this->_window.clear();
	this->_window.display();
}