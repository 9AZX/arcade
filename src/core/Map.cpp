/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Map
*/

#include "Map.hpp"
#include <fstream>

Map::Map(std::string path)
{
    char c = 0;
    std::string buf;
    std::ifstream file;

    file.open(path);
    if (!file)
    {
        std::cerr << "Error: Couldn't open the file" << std::endl;
    }

    while (!file.eof())
    {
        getline(file, buf);
        if (buf.compare(0, 8, "#bitmap:") == 0)
        {
            std::cout << buf << std::endl;
            while (file.get(c) && file.is_open() && (c != '\n' && _map.back() != '\n'))
            {
                c -= '0';
                this->_map.push_back(static_cast<byteMap>(c));
            }
        }
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