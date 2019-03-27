/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanModule
*/

#include "PacmanModule.hpp"
#include <iostream>

PacmanModule::PacmanModule(ICoreModule *core) : _core(core) {
  this->_core->storeGameEntity(
      new GameEntity('C', "./assets/pacman/pacman.png", "Player",
                     std::make_pair<int, int>(10, 12)));
  this->_core->storeGameEntity(new GameEntity('M', "./assets/pacman/ghost.png",
                                              "Enemy1",
                                              std::make_pair<int, int>(9, 10)));
  this->_core->storeGameEntity(
      new GameEntity('M', "./assets/pacman/ghost.png", "Enemy2",
                     std::make_pair<int, int>(11, 10)));
}

void PacmanModule::play() {
  this->_core->renderAll();
  while (this->_core->isOpen()) {
    this->_core->getInputs();
  }
}

void PacmanModule::pauseMenu() {}

void PacmanModule::endGame() {}

long PacmanModule::getScore() const { return 0; }

const GameMap &PacmanModule::getMap() const noexcept { return this->_map; }
