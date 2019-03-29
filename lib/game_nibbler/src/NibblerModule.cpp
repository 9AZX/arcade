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
    this->_core->getEntity("Player").setPos(
        std::pair<int, int>(playerPos.first + 1, playerPos.second));
  } else if (keys.back() == LEFT) {
    this->_core->getEntity("Player").setRotation(270);
    this->_core->getEntity("Player").setPos(
        std::pair<int, int>(playerPos.first - 1, playerPos.second));
  } else if (keys.back() == UP) {
    this->_core->getEntity("Player").setRotation(0);
    this->_core->getEntity("Player").setPos(
        std::pair<int, int>(playerPos.first, playerPos.second - 1));
  } else if (keys.back() == DOWN) {
    this->_core->getEntity("Player").setRotation(180);
    this->_core->getEntity("Player").setPos(
        std::pair<int, int>(playerPos.first, playerPos.second + 1));
  }
}