/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SnakeModule
*/

#include "NibblerModule.hpp"
#include <iostream>

NibblerModule::NibblerModule(ICoreModule *core) : _core(core) {
  this->_core->storeGameEntity(
      new GameEntity('0', "./assets/nibbler/head-snake.png", 0,
                     std::make_pair<int, int>(12, 10), false));
  this->_core->storeGameEntity(
      new GameEntity('O', "./assets/nibbler/body-snake.png", 1,
                     std::make_pair<int, int>(11, 10), false));
  this->_core->storeGameEntity(
      new GameEntity('o', "./assets/nibbler/tail-snake.png", 99,
                     std::make_pair<int, int>(10, 10), false));
  this->_core->storeGameEntity(
      new GameEntity('P', "./assets/nibbler/apple.png", 100,
                     std::make_pair<int, int>(14, 16), false));
  this->_core->storeGameEntity(
      new GameEntity('P', "./assets/nibbler/apple.png", 101,
                     std::make_pair<int, int>(14, 6), false));
  this->_core->storeGameEntity(
      new GameEntity('P', "./assets/nibbler/apple.png", 102,
                     std::make_pair<int, int>(6, 6), false));
  this->_core->storeGameEntity(
      new GameEntity('P', "./assets/nibbler/apple.png", 103,
                     std::make_pair<int, int>(6, 16), false));
  this->_core->storeGameEntity(
      new GameEntity('P', "./assets/nibbler/apple.png", 104,
                     std::make_pair<int, int>(10, 14), false));
  this->_core->storeGameEntity(
      new GameEntity('P', "./assets/nibbler/apple.png", 105,
                     std::make_pair<int, int>(10, 4), false));
}

void NibblerModule::destructor() { delete this; }

void NibblerModule::play() {
  Events event;

  while (this->_core->isOpen()) {
    this->_core->renderAll();
    event = this->_core->getInputs();
    if (event.keys.size() > 0) {
      this->computeInput(event.keys);
    }
    forward();
    bodyMove();
    checkApple();
  }
}

void NibblerModule::pauseMenu() {}

void NibblerModule::endGame() {}

long NibblerModule::getScore() const { return 0; }

const GameMap &NibblerModule::getMap() const noexcept { return this->_map; }

void NibblerModule::computeInput(std::vector<enum gameInputs> keys) {
  std::pair<int, int> playerPos = this->_core->getEntity(0).getPos();
  auto ch = keys.back();

  switch (ch) {
    case RIGHT:
      resetPos();
      makeMove(std::pair<int, int>(this->_core->getEntity(0).getPos().first + 1,
                                   this->_core->getEntity(0).getPos().second));
      this->_core->getEntity(0).setRotation(90);
      this->_core->getEntity(0).moveRight = true;
      break;
    case LEFT:
      resetPos();
      makeMove(std::pair<int, int>(this->_core->getEntity(0).getPos().first - 1,
                                   this->_core->getEntity(0).getPos().second));
      this->_core->getEntity(0).setRotation(270);
      this->_core->getEntity(0).moveLeft = true;
      break;
    case UP:
      resetPos();
      makeMove(
          std::pair<int, int>(this->_core->getEntity(0).getPos().first,
                              this->_core->getEntity(0).getPos().second - 1));
      this->_core->getEntity(0).setRotation(0);
      this->_core->getEntity(0).moveUp = true;
      break;
    case DOWN:
      resetPos();
      makeMove(
          std::pair<int, int>(this->_core->getEntity(0).getPos().first,
                              this->_core->getEntity(0).getPos().second + 1));
      this->_core->getEntity(0).setRotation(180);
      this->_core->getEntity(0).moveDown = true;
      break;
    case ESCAPE:
      std::cout << "You quit the game" << std::endl;
      break;
  }
}

void NibblerModule::resetPos() {
  this->_core->getEntity(0).moveUp = false;
  this->_core->getEntity(0).moveDown = false;
  this->_core->getEntity(0).moveLeft = false;
  this->_core->getEntity(0).moveRight = false;
}

bool NibblerModule::checkCollision(std::pair<int, int> nextPos) {
  char cell = this->_map.grid.at(nextPos.second - 1).at(nextPos.first - 1);
  if (this->_map.blockProperties.at(cell).isSolid) return false;
  return true;
}

void NibblerModule::checkApple() {
  std::pair<int, int> playerPos = this->_core->getEntity(0).getPos();

  for (unsigned int i = 0; i < appleRemain; i++) {
    if ((playerPos.first == _core->getEntity(i + 100).getPos().first) &&
        (playerPos.second == _core->getEntity(i + 100).getPos().second) &&
        this->_core->getEntity(i + 100).isAlive) {
      snakeWidth++;
      appleRemain--;
      this->_core->getEntity(i + 100).isAlive = false;
      this->_core->storeGameEntity(new GameEntity(
          'O', "./assets/nibbler/body-snake.png", snakeWidth,
          this->_core->getEntity(snakeWidth - 1).getPos(), false));
    }
  }
}

void NibblerModule::bodyMove() {
  for (unsigned int it = 0; it < snakeWidth; ++it) {
    if (this->_core->getEntity(it).getPrevPos().first != -1)
      this->_core->getEntity(it + 1).setPos(
          this->_core->getEntity(it).getPrevPos());
  }
  if (this->_core->getEntity(snakeWidth).getPrevPos().first != -1)
    this->_core->getEntity(99).setPos(
        this->_core->getEntity(snakeWidth).getPrevPos());
}

void NibblerModule::makeMove(std::pair<int, int> pos) {
  if (this->checkCollision(pos)) this->_core->getEntity(0).setPos(pos);
}

void NibblerModule::forward() {
  AEntity &player = this->_core->getEntity(0);
  if (player.moveDown) {
    makeMove(
        std::pair<int, int>(player.getPos().first, player.getPos().second + 1));
  } else if (player.moveUp) {
    makeMove(
        std::pair<int, int>(player.getPos().first, player.getPos().second - 1));
  } else if (player.moveLeft) {
    makeMove(
        std::pair<int, int>(player.getPos().first - 1, player.getPos().second));
  } else if (player.moveRight) {
    makeMove(
        std::pair<int, int>(player.getPos().first + 1, player.getPos().second));
  }
}
