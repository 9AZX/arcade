/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SfmlModule
*/

#include "SfmlModule.hpp"

SfmlModule::SfmlModule() {
  this->_window = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(SFML_WINDOW_HEIGHT, SFML_WINDOW_WIDTH), SFML_WINDOW_NAME);
  this->_window->setFramerateLimit(SFML_WINDOW_FRAMERATE);
}

SfmlModule::~SfmlModule() {}

void SfmlModule::initGraphics(GameMap map) {
  sf::Texture wallTexture;
  sf::Sprite wallSprite;

  wallTexture.loadFromFile(map.blockProperties['#'].assetPath);
  wallSprite.setOrigin(16, 16);
  this->_sprites.insert({"wall", std::make_pair(wallSprite, wallTexture)});
  this->_sprites["wall"].first.setTexture(this->_sprites["wall"].second, true);
}

std::vector<enum gameInputs> SfmlModule::getInputs() {
  std::vector<enum gameInputs> mdr;
  return mdr;
}

void SfmlModule::displayEntity(AEntity &) {}

void SfmlModule::displayMap(GameMap map) {
  if (this->_sprites.empty()) {
    std::cout << "init graphics" << std::endl;
    this->initGraphics(map);
  }
  for (int ith = 0; ith < map.height; ith++) {
    for (int itl = 0; itl < map.width; itl++) {
      if (map.grid[ith][itl] == '#') {
        this->_sprites["wall"].first.setPosition(itl * 32 + 32, ith * 32 + 32);
        this->_window->draw(this->_sprites["wall"].first);
        std::cout << "NDR";
      }
    }
  }
  this->_window->display();
}

void SfmlModule::destructor() { delete this; }

void SfmlModule::renderTextEntity(AEntity &) const {}

void SfmlModule::renderGameEntity(AEntity &) const {}

void SfmlModule::matchInputs(std::vector<enum gameInputs> &inputs,
                             sf::Keyboard::Key key) {
  (void)inputs;
  (void)key;
}
