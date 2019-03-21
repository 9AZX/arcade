/*
** EPITECH PROJECT, 2019
** entry
** File description:
** Entry point for the lib sfml.
*/

#include <iostream>
#include "SfmlModule.hpp"

extern "C" void *EntryGraph();

void *EntryGraph()
{
	std::cout << "call (sfml): ok" << std::endl;
	return new SfmlModule;
}
