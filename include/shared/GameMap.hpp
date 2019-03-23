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

#define MAP1 "111111111111111111110000000000000000011011011101011101101" \
			 "100000000000000000110110101111101011011000010001000100001" \
			 "111101110101110111100010100000001010001111010110110101111" \
			 "000000010001000000011110101111101011110001010000000101000" \
			 "111101011111010111110000000010000000011011011101011101101" \
			 "100100000000000100111010101111101010111000010001000100001" \
			 "101111110101111110110000000000000000011111111111111111111"

enum byteMap {
	VOID = '\n',
	GROUND = 0,
	WALL = 1,
	FOOD = 2,
	EXTRA = 3
};

struct GameMap {
	const int height;
	const int width;
	std::vector<std::string> grid;
};

#endif /* !MAP_HPP_ */
