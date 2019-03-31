/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_

#include <iostream>
#include <vector>
#include "Entity.hpp"
#include "GameEntity.hpp"
#include "GameMap.hpp"
#include "Inputs.hpp"
#include "TextEntity.hpp"

class IDisplayModule {
 public:
  virtual bool displayEntity(AEntity &) = 0;
  virtual void displayMap(GameMap) = 0;
  virtual void destructor() = 0;
  virtual bool isOpen() const = 0;
  virtual Events getInputs() = 0;
  virtual const std::string &getLibraryName() const noexcept = 0;
  virtual void refreshWindow() const noexcept = 0;
  virtual void startMusic(std::string) = 0;
};

#endif /* !IDISPLAYMODULE_HPP_ */
