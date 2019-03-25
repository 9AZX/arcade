/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SnakeModule
*/

#include "NibblerModule.hpp"
#include <iostream>

NibblerModule::NibblerModule(ICoreModule *core) : _core(core) {}

void NibblerModule::play() {
  this->_core->renderAll();
  while (this->_core->isOpen()) {
  }
}

void NibblerModule::pauseMenu() {}

void NibblerModule::endGame() {}

long NibblerModule::getScore() const { return 0; }

const GameMap &NibblerModule::getMap() const noexcept { return this->_map; }