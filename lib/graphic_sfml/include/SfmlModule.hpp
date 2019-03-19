/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SfmlModule
*/

#ifndef	SFMLMODULE_HPP_
#define	SFMLMODULE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "IDisplayModule.hpp"

class SfmlModule : public  IDisplayModule
{
public:
	SfmlModule();
	~SfmlModule();
  	void initScreen() override;
	void print_map(Map) override {};
	void drawScreen();

private:
	sf::RenderWindow _window;
};

#endif	/* !SFMLMODULE_HPP_ */
