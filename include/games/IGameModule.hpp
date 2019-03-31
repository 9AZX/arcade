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
#include <fstream>
#include <memory>

#include "GameEntity.hpp"
#include "GameMap.hpp"
#include "TextEntity.hpp"

class IGameModule {
 public:
  virtual ~IGameModule() = default;

 public:
  virtual void play() = 0;
  virtual void pauseMenu() = 0;
  virtual void endGame() = 0;
  virtual const GameMap &getMap() const noexcept = 0;
  virtual long getScore() const = 0;
  virtual void destructor() = 0;
  virtual bool checkCollision(std::pair<int, int> nextPos) = 0;
  virtual std::string getMusicPath() = 0;

 protected:
  long _score = 0;
  std::string musicPath;
};

#endif /* !IGAMEMODULE_HPP_ */
