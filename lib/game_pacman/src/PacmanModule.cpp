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
      new GameEntity('C', "assets/pacman/pacmans.png", "Player"));
  this->_core->storeGameEntity(
      new GameEntity('M', "assets/pacman/ghost.png", "Enemy1"));
  this->_core->storeGameEntity(
      new GameEntity('M', "assets/pacman/ghost.png", "Enemy2"));
}

void PacmanModule::play() {
  this->_core->renderAll();
  while (this->_core->isOpen()) {
    std::cout << this->_core->getInputs().ascii;
  }
}

void PacmanModule::pauseMenu() {}

void PacmanModule::endGame() {}

long PacmanModule::getScore() const { return 0; }

const GameMap &PacmanModule::getMap() const noexcept { return this->_map; }
