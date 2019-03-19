/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Map
*/

#include "Map.hpp"
#include <fstream>

Map::Map(std::string map)
{
	this->_map = map;
	this->ncurses_ground = ' ';
	this->ncurses_wall = '#';
	this->ncurses_player = 'G';
	this->ncurses_food = ' ';
	this->ncurses_extra = ' ';
	this->ncurses_void_entity = 'A';
}

Map::byteMap Map::getMap(unsigned int i)
{
	return (Map::byteMap)(this->_map[i] - '0');
}
