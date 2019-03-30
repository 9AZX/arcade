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
      new GameEntity('C', "./assets/pacman/pacmans.png", 0,
                     std::make_pair<int, int>(10, 12), true));
  this->_core->storeGameEntity(
      new GameEntity('M', "./assets/pacman/ghost.png", 201,
                     std::make_pair<int, int>(9, 10), false));
  this->_core->storeGameEntity(
      new GameEntity('M', "./assets/pacman/ghost.png", 202,
                     std::make_pair<int, int>(11, 10), false));
}

bool PacmanModule::checkCollision(std::pair<int, int> nextPos) {
  char cell = this->_map.grid.at(nextPos.second - 1).at(nextPos.first - 1);
  if (this->_map.blockProperties.at(cell).isSolid) return false;
  return true;
}

void PacmanModule::computeInput(std::vector<enum gameInputs> keys) {
  std::pair<int, int> playerPos = this->_core->getEntity(0).getPos();

  if (keys.back() == RIGHT && !this->_core->getEntity(0).isMoving) {
    this->_core->getEntity(0).setRotation(0);
    if (this->checkCollision(
            std::pair<int, int>(playerPos.first + 1, playerPos.second))) {
      this->_core->getEntity(0).moveRight = true;
      this->_core->getEntity(0).isMoving = true;
      this->_core->getEntity(0).setPos(
          std::pair<int, int>(playerPos.first + 1, playerPos.second));
    }
  } else if (keys.back() == LEFT && !this->_core->getEntity(0).isMoving) {
    this->_core->getEntity(0).moveLeft = true;
    if (this->checkCollision(
            std::pair<int, int>(playerPos.first - 1, playerPos.second))) {
      this->_core->getEntity(0).isMoving = true;
      this->_core->getEntity(0).setRotation(180);
      this->_core->getEntity(0).setPos(
          std::pair<int, int>(playerPos.first - 1, playerPos.second));
    }
  } else if (keys.back() == UP && !this->_core->getEntity(0).isMoving) {
    this->_core->getEntity(0).moveUp = true;
    if (this->checkCollision(
            std::pair<int, int>(playerPos.first, playerPos.second - 1))) {
      this->_core->getEntity(0).isMoving = true;
      this->_core->getEntity(0).setRotation(270);
      this->_core->getEntity(0).setPos(
          std::pair<int, int>(playerPos.first, playerPos.second - 1));
    }
  } else if (keys.back() == DOWN && !this->_core->getEntity(0).isMoving) {
    this->_core->getEntity(0).moveDown = true;
    if (this->checkCollision(
            std::pair<int, int>(playerPos.first, playerPos.second + 1))) {
      this->_core->getEntity(0).isMoving = true;
      this->_core->getEntity(0).setRotation(90);
      this->_core->getEntity(0).setPos(
          std::pair<int, int>(playerPos.first, playerPos.second + 1));
    }
  } else if (keys.back() == ESCAPE) {
    std::cout << "You quit the game" << std::endl;
  }
}

void PacmanModule::play() {
  Events event;

  while (this->_core->isOpen()) {
    this->_core->renderAll();
    event = this->_core->getInputs();
    if (event.keys.size() > 0) this->computeInput(event.keys);
  }
}

void PacmanModule::pauseMenu() {}

void PacmanModule::endGame() {}

long PacmanModule::getScore() const { return 0; }

const GameMap &PacmanModule::getMap() const noexcept { return this->_map; }

void PacmanModule::checkApple() {}