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
  AEntity(int id, std::pair<int, int> pos, bool anim)
      : id(id), _pos(pos), _isAnimated(anim) {}
  virtual ~AEntity() = default;
  std::pair<int, int> getPos() { return _pos; };
  enum EntityType getType() const noexcept { return _type; };
  void setPos(std::pair<int, int> newPos) noexcept {
    _prevPos = _pos;
    _pos = newPos;
  }
  int getRotation() { return this->_rotation; }
  void setRotation(int angle) { _rotation = angle; }
  bool getAnimated() const noexcept { return _isAnimated; };
  std::pair<int, int> getPrevPos() const noexcept { return _prevPos; };

  const int id;
  int animIt = 0;
  bool isMoving = false;
  bool moveRight = false;
  bool moveLeft = false;
  bool moveUp = false;
  bool moveDown = false;
  bool moveRandom = false;
  bool isAlive = true;

 protected:
  std::pair<int, int> _pos;
  std::pair<int, int> _prevPos = {-1, -1};
  std::pair<float, float> _absCurrentPos;
  bool _isAnimated;
  int _rotation = 0;
  enum EntityType _type = DEFAULT;
};

#endif /* !ENTITY_HPP_ */
