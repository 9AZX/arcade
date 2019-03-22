/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SfmlModule
*/

#include "SfmlModule.hpp"

std::vector<enum gameInputs> SfmlModule::getInputs()
{
	std::vector<enum gameInputs> mdr;
	return mdr;
}

void SfmlModule::displayEntity(AEntity &)
{
}
void SfmlModule::displayMap()
{
}
void SfmlModule::renderTextEntity(AEntity &) const
{
}
void SfmlModule::renderGameEntity(AEntity &) const
{
}

void SfmlModule::matchInputs(std::vector<enum gameInputs> &inputs, sf::Keyboard::Key key)
{
	(void)inputs;
	(void)key;
}
