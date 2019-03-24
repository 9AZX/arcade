/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <map>
#include <memory>
#include <vector>

enum BlockColor { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

struct GameMap {
  const int height;
  const int width;
  std::vector<std::string> grid;
  std::map<char, struct MapBlock> blockProperties;
};

struct MapBlock {
  std::string assetPath;
  bool isSolid;
  enum BlockColor color;
  enum BlockColor colorBackground;
};

#endif /* !MAP_HPP_ */
