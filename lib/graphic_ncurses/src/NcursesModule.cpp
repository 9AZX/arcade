/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NcursesModule
*/

#include "NcursesModule.hpp"

void NcursesModule::initScreen()
{
}

void NcursesModule::print_map(Map map_info)
{
	unsigned int idx[3] = {0};

	for (idx[0] = 0; idx[0] < 21; ++idx[0])
	{
		for (idx[1] = 0; idx[1] < 19; ++idx[1])
		{
			switch (map_info.getMap(idx[2]))
			{
			case Map::GROUND:
				addch(map_info.ncurses_ground);
				break;
			case Map::WALL:
				addch(map_info.ncurses_wall);
				break;
			case Map::FOOD:
				addch(map_info.ncurses_food);
				break;
			case Map::EXTRA:
				addch(map_info.ncurses_extra);
				break;
			default:
				addch(map_info.ncurses_ground);
				break;
			}
			idx[2] += 1;
		}
		addch('\n');
	}
}
