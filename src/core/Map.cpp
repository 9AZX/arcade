/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Map
*/

#include "Map.hpp"

Map::Map(std::string path)
{
    // For testing only at this time
    std::string map = "111111111111111111112222222222222222211311211121211121131122222222222222222112112121111121211211222212221222122221111121110101112111100012100000001210001111210110110121111000020010001002000011112101111101211110001210000000121000111121011111012111112222222212222222211211211121211121121132122222222222123111212121111121212111222212221222122221121111112121111112112222222222222222211111111111111111111";
    for (unsigned i = 0; i < map.length(); ++i) {
        byteMap c = static_cast<byteMap>(map.at(i) - '0');
        this->_map.push_back(c);
    }
    this->ncurses_ground = ' ';
    this->ncurses_wall = '#';
    this->ncurses_player = 'G';
    this->ncurses_food = ' ';
    this->ncurses_extra = ' ';
    this->ncurses_void_entity = 'A';

}

Map::~Map()
{
}

Map::byteMap Map::getMap(unsigned int i)
{
    return this->_map[i];
}