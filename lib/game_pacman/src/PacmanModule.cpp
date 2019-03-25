/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanModule
*/

#include "PacmanModule.hpp"
#include <iostream>

PacmanModule::PacmanModule(ICoreModule *core) : _core(core) {}

void PacmanModule::play() {
  this->_core->renderAll();
  while (this->_core->isOpen()) {
  }
}

void PacmanModule::pauseMenu() {}

void PacmanModule::endGame() {}

long PacmanModule::getScore() const { return 0; }

const GameMap &PacmanModule::getMap() const noexcept { return this->_map; }
