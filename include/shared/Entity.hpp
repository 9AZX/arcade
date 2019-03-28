/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <iostream>

class AEntity {
 public:
  enum EntityType { DEFAULT, GAME, TEXT };

 public:
  AEntity() = delete;
  AEntity(std::string id, std::pair<int, int> pos) : id(id), _pos(pos) {}
  virtual ~AEntity() = default;
  std::pair<int, int> getPos() { return _pos; };
  enum EntityType getType() const noexcept { return _type; };
  void setPos(std::pair<int, int> newPos) noexcept { _pos = newPos; }
  int getRotation() { return this->_rotation; }
  void setRotation(int angle) { _rotation = angle; }

  const std::string id;
  bool isAnimated = true;
  int animIt = 0;

 protected:
  std::pair<int, int> _pos;
  int _rotation = 0;
  enum EntityType _type = DEFAULT;
};

#endif /* !ENTITY_HPP_ */
