/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <memory>
#include <iostream>
#include <vector>

class Map
{
  public:
	enum byteMap
	{
		VOID = -1,
		GROUND = 0,
		WALL = 1,
		FOOD = 2,
		EXTRA = 3
	};

	Map(std::string path);
	~Map();

	std::string assets_void = "";
	std::string assets_ground = "";
	std::string assets_wall = "";
	std::string assets_player = "";
	std::string assets_player_body = "";
	std::string assets_void_entity = "";

	char ncurses_void;
	char ncurses_ground;
	char ncurses_wall;
	char ncurses_player;
	char ncurses_player_body;
	char ncurses_void_entity;
	char ncurses_food;
	char ncurses_extra;

	byteMap getMap(unsigned int);
  private:
	std::vector<byteMap> _map;
};

#endif /* !MAP_HPP_ */
