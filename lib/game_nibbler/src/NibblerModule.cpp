/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SnakeModule
*/

#include "NibblerModule.hpp"
#include <iostream>

NibblerModule::NibblerModule(ICoreModule *core) : _core(core) {
  srand((unsigned)time(NULL));
  this->_core->storeGameEntity(
      new GameEntity('0', "./assets/nibbler/head-snake.png", "Player",
                     std::make_pair<int, int>(10, 10), false));
  this->_core->storeGameEntity(
      new GameEntity('0', "./assets/nibbler/tail-snake.png", "PlayerTail",
                     std::make_pair<int, int>(10, 11), false));
  this->_core->storeGameEntity(new GameEntity(
      'P', "./assets/nibbler/apple.png", "Apple",
      std::make_pair<int, int>(rand() % 18 + 1, rand() % 18 + 1), false));
}

void NibblerModule::play() {
  Events event;

  while (this->_core->isOpen()) {
    this->_core->renderAll();
    event = this->_core->getInputs();
    if (event.keys.size() > 0) this->computeInput(event.keys);
  }
}

void NibblerModule::pauseMenu() {}

void NibblerModule::endGame() {}

long NibblerModule::getScore() const { return 0; }

const GameMap &NibblerModule::getMap() const noexcept { return this->_map; }

void NibblerModule::computeInput(std::vector<enum gameInputs> keys) {
  std::pair<int, int> playerPos = this->_core->getEntity("Player").getPos();

  if (keys.back() == RIGHT) {
    this->_core->getEntity("Player").setRotation(90);
    if (this->checkCollision(
            std::pair<int, int>(playerPos.first + 1, playerPos.second)))
      this->_core->getEntity("Player").setPos(
          std::pair<int, int>(playerPos.first + 1, playerPos.second));
  } else if (keys.back() == LEFT) {
    this->_core->getEntity("Player").setRotation(270);
    if (this->checkCollision(
            std::pair<int, int>(playerPos.first - 1, playerPos.second)))
      this->_core->getEntity("Player").setPos(
          std::pair<int, int>(playerPos.first - 1, playerPos.second));
  } else if (keys.back() == UP) {
    this->_core->getEntity("Player").setRotation(0);
    if (this->checkCollision(
            std::pair<int, int>(playerPos.first, playerPos.second - 1)))
      this->_core->getEntity("Player").setPos(
          std::pair<int, int>(playerPos.first, playerPos.second - 1));
  } else if (keys.back() == DOWN) {
    this->_core->getEntity("Player").setRotation(180);
    if (this->checkCollision(
            std::pair<int, int>(playerPos.first, playerPos.second + 1)))
      this->_core->getEntity("Player").setPos(
          std::pair<int, int>(playerPos.first, playerPos.second + 1));
  } else if (keys.back() == ESCAPE) {
    std::cout << "You quit the game" << std::endl;
  }
}

bool NibblerModule::checkCollision(std::pair<int, int> nextPos) {
  // std::cout << nextPos.second - 1 << ", " << nextPos.first - 1 << " ";
  // std::cout << this->_map.grid.at(nextPos.second - 1).at(nextPos.first - 1)
  //           << std::endl;
  char cell = this->_map.grid.at(nextPos.second - 1).at(nextPos.first - 1);
  // this->_map.blockProperties[this->_map.grid.at(nextPos.second - 1)
  //                                .at(nextPos.first - 1)];
  if (this->_map.blockProperties.at(cell).isSolid) return false;
  // this->_map.grid.at(nextPos.second).at(nextPos.first);
  return true;
}

void NibblerModule::checkApple() {}

void NibblerModule::bodyMove() {}