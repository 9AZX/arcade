/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NcursesModule
*/

#include "NcursesModule.hpp"

NcursesModule::NcursesModule()
{
}

NcursesModule::~NcursesModule()
{
}

void NcursesModule::print_map(Map map_info)
{
    unsigned int total = 0;
    for (unsigned int b = 0; b < 21 ; ++b) {
        for (unsigned int i = 0; i < 19 ; ++i) {
            switch (map_info.getMap(total))
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
            total += 1;
        }
        total += 1;
        addch('\n');
    }
}