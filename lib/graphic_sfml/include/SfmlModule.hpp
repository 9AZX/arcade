/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SfmlModule
*/

#ifndef SFMLMODULE_HPP_
#define SFMLMODULE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "IDisplayModule.hpp"
#include "IRender.hpp"

class SfmlModule : public IDisplayModule, public IRender
{
public:
	SfmlModule();
	~SfmlModule() = default;

	std::vector<enum gameInputs> getInputs() final;
	void displayEntity(AEntity &) final;
	void displayMap() final;
	void renderTextEntity(AEntity &) const final;
	void renderGameEntity(AEntity &) const final;

private:
	std::unique_ptr<sf::Window> _window;
	void matchInputs(std::vector<enum gameInputs> &inputs, sf::Keyboard::Key key);
};

#endif /* !SFMLMODULE_HPP_ */
