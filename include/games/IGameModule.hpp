/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <stdlib.h>
#include <time.h>
#include <memory>
#include "GameEntity.hpp"
#include "GameMap.hpp"

class IGameModule {
 public:
  virtual ~IGameModule() = default;

 public:
  virtual void play() = 0;
  virtual void pauseMenu() = 0;
  virtual void endGame() = 0;
  virtual const GameMap &getMap() const noexcept = 0;
  virtual long getScore() const = 0;
  virtual bool checkCollision(std::pair<int, int> nextPos) = 0;

 private:
  long _score = -1;
};

#endif /* !IGAMEMODULE_HPP_ */
