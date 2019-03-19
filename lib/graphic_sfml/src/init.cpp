/*
** EPITECH PROJECT, 2019
** entry
** File description:
** Entry point for the lib sfml.
*/

#include <iostream>
#include "SfmlModule.hpp"

extern "C" void EntryGraph();

void EntryGraph()
{
	Map map(MAP1);
	SfmlModule sfml;

	sfml.initScreen();
	sfml.drawScreen();
	std::cout << "call (sfml): ok" << std::endl;
}
