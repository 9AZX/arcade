/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SfmlModule
*/

#ifndef	SFMLMODULE_HPP_
#define	SFMLMODULE_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "IDisplayModule.hpp"
#include "IRender.hpp"

#define SFML_WINDOW_NAME "Pacman"
#define SFML_WINDOW_WIDTH 650
#define SFML_WINDOW_HEIGHT 700
#define SFML_WINDOW_FRAMERATE 60

class SfmlModule : public IDisplayModule, public IRender
{
public:
	SfmlModule();
	virtual ~SfmlModule();

public:
	std::vector<enum gameInputs> getInputs() final;
	void displayEntity(AEntity&) final;
	void displayMap(GameMap) final;
	void renderTextEntity(AEntity&) const final;
	void renderGameEntity(AEntity&) const final;
	void destructor() final;

private:
	std::unique_ptr<sf::Window> _window;
	void matchInputs(std::vector<enum gameInputs>& inputs, sf::Keyboard::Key key);
};

#endif	/* !SFMLMODULE_HPP_ */
