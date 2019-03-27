/*
 ** EPITECH PROJECT, 2019
 ** GameEntity
 ** File description:
 ** Class game entity
 */

#ifndef GAME_ENTITY_HPP_
#define GAME_ENTITY_HPP_

#include "Entity.hpp"

class GameEntity : public AEntity {
 public:
  GameEntity() = delete;
  GameEntity(char assetChar, std::string assetPath, std::string id,
             std::pair<int, int> pos)
      : AEntity(id, pos), assetChar(assetChar), assetPath(assetPath) {
    _type = AEntity::GAME;
  }
  ~GameEntity() = default;

  const char assetChar;
  const std::string assetPath;
};

#endif /* ifndef GAME_ENTITY_HPP_ */