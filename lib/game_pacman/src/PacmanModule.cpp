/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanModule
*/

#include "PacmanModule.hpp"
#include <iostream>

PacmanModule::PacmanModule(ICoreModule *core) : _core(core) {
  this->initPacgums();
  this->_core->storeGameEntity(
      new GameEntity('C', "./assets/pacman/pacmans.png", 0,
                     std::make_pair<int, int>(10, 12), true));
  this->_core->storeGameEntity(
      new GameEntity('M', "./assets/pacman/ghost_red.png", 401,
                     std::make_pair<int, int>(9, 10), false));
  this->_core->getEntity(401).moveRandom = true;
  this->_core->storeGameEntity(
      new GameEntity('M', "./assets/pacman/ghost_blue.png", 402,
                     std::make_pair<int, int>(11, 10), false));
  this->_core->getEntity(402).moveRandom = true;

  this->_core->storeGameEntity(
      new GameEntity('M', "./assets/pacman/ghost_green.png", 403,
                     std::make_pair<int, int>(10, 10), false));
  this->_core->getEntity(403).moveRandom = true;

  this->_core->storeGameEntity(
      new GameEntity('M', "./assets/pacman/ghost_yellow.png", 404,
                     std::make_pair<int, int>(10, 9), false));
  this->_core->getEntity(404).moveRandom = true;
  this->_core->storeGameEntity(
      new TextEntity(420, "Score: 0", TextEntity::WHITE,
                     std::make_pair<int, int>(1, 22), false));
  this->_core->storeGameEntity(
      new TextEntity(421, "Highscore: ", TextEntity::WHITE,
                     std::make_pair<int, int>(1, 23), false));
}

void PacmanModule::initPacgums() {
  for (unsigned int it = 0; it < this->_pacgumPos.size(); it++) {
    this->_core->storeGameEntity(
        new GameEntity('*', "./assets/pacman/pacgum.png", 1000 + it,
                       this->_pacgumPos[it], false));
  }
}

void PacmanModule::destructor() { delete this; }

bool PacmanModule::checkCollision(std::pair<int, int> nextPos) {
  if (nextPos.first == 20 && nextPos.second == 10) {
    this->_core->getEntity(0).setPos(std::pair<int, int>(1, 10));
    return false;
  }
  if (nextPos.first == 0 && nextPos.second == 10) {
    this->_core->getEntity(0).setPos(std::pair<int, int>(19, 10));
    this->_core->getEntity(0).setRotation(180);
    return false;
  }
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
    this->checkApple();
    this->collisionGhost();
    this->getScore();
  }
}

void PacmanModule::pauseMenu() {}

void PacmanModule::endGame() {}

long PacmanModule::getScore() const {
  TextEntity *entity = static_cast<TextEntity *>(&this->_core->getEntity(420));

  entity->setText("Score: " + std::to_string(_score));
  return _score;
}

const GameMap &PacmanModule::getMap() const noexcept { return this->_map; }

void PacmanModule::checkApple() {
  std::pair<int, int> playerPos = this->_core->getEntity(0).getPos();

  for (unsigned int i = 0; i < this->_pacgumPos.size(); i++) {
    if ((playerPos.first == this->_core->getEntity(i + 1000).getPos().first) &&
        (playerPos.second ==
         this->_core->getEntity(i + 1000).getPos().second) &&
        (this->_core->getEntity(i + 1000).isAlive)) {
      pacgumRemain--;
      _score += 10;
      this->_core->getEntity(i + 1000).isAlive = false;
    }
  }
}

void PacmanModule::collisionGhost() {
  std::pair<int, int> playerPos = this->_core->getEntity(0).getPos();

  for (unsigned int i = 401; i < 405; i++) {
    if ((playerPos.first == this->_core->getEntity(i).getPos().first) &&
        (playerPos.second == this->_core->getEntity(i).getPos().second)) {
      std::cout << "you loose" << std::endl;
      this->endGame();
    }
  }
}