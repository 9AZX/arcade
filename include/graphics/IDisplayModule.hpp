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
#include "GameMap.hpp"
#include "Inputs.hpp"

class IDisplayModule {
 public:
  virtual std::vector<enum gameInputs> getInputs() = 0;
  virtual void displayEntity(AEntity &) = 0;
  virtual void displayMap(GameMap) = 0;
  virtual void destructor() = 0;
  virtual bool isOpen() const = 0;
};

#endif /* !IDISPLAYMODULE_HPP_ */
