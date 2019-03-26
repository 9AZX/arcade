/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** ICoreModule
*/

#ifndef ICOREMODULE_HPP_
#define ICOREMODULE_HPP_

#include <vector>
#include "Entity.hpp"
#include "GameMap.hpp"
#include "Inputs.hpp"

class ICoreModule {
 public:
  virtual ~ICoreModule() = default;
  virtual void storeGameEntity(AEntity* entity) = 0;
  virtual AEntity& getEntity(std::string name) = 0;
  virtual Events getInputs() = 0;
  virtual void renderAll() = 0;
  virtual void setMap(GameMap& map) = 0;
  virtual bool isOpen() const = 0;

 protected:
  std::vector<AEntity> _entities;
};

#endif /* !ICOREMODULE_HPP_ */
