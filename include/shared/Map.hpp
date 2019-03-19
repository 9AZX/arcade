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

#define	MAP1	"111111111111111111110000000000000000011011011101011101101"	\
				"100000000000000000110110101111101011011000010001000100001"	\
				"111101110101110111100010100000001010001111010110110101111"	\
				"000000010001000000011110101111101011110001010000000101000"	\
				"111101011111010111110000000010000000011011011101011101101"	\
				"100100000000000100111010101111101010111000010001000100001"	\
				"101111110101111110110000000000000000011111111111111111111"

class Map
{
public:
	Map(std::string map);
	~Map() = default;

public:
	enum byteMap
	{
		VOID = '\n',
		GROUND = 0,
		WALL = 1,
		FOOD = 2,
		EXTRA = 3
	};
	std::string assets_void = "";
	std::string assets_ground = "";
	std::string assets_wall = "";
	std::string assets_player = "";
	std::string assets_player_body = "";
	std::string assets_void_entity = "";
	char ncurses_void = -1;
	char ncurses_ground = -1;
	char ncurses_wall = -1;
	char ncurses_player = -1;
	char ncurses_player_body = -1;
	char ncurses_void_entity = -1;
	char ncurses_food = -1;
	char ncurses_extra = -1;

	byteMap getMap(unsigned int);

private:
	std::string _map;
};

#endif /* !MAP_HPP_ */
