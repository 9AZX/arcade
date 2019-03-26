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
  this->_sprites["wall"].first.setColor(sf::Color::Blue);
}

Events SfmlModule::getInputs() {
  Events actual;
  this->_window->pollEvent(this->eventSFML);

  switch (this->eventSFML.type) {
    case sf::Event::Closed:
      this->_window->close();
      break;
    case sf::Event::KeyPressed:
      this->matchInputs(actual, this->eventSFML.key.code);
      break;
    case sf::Event::TextEntered:
      if (eventSFML.text.unicode > 64 && eventSFML.text.unicode < 123)
        actual.ascii += static_cast<char>(eventSFML.text.unicode);
      break;
    default:
      break;
  }
  return actual;
}

void SfmlModule::displayEntity(AEntity &) {}

void SfmlModule::displayMap(GameMap map) {
  if (this->_sprites.empty()) {
    this->initGraphics(map);
  }
  for (int ith = 0; ith < map.height; ith++) {
    for (int itl = 0; itl < map.width; itl++) {
      if (map.grid[ith][itl] == '#') {
        this->_sprites["wall"].first.setPosition(itl * 32 + 32, ith * 32 + 32);
        this->_window->draw(this->_sprites["wall"].first);
      }
    }
  }
  this->_window->display();
}

bool SfmlModule::isOpen() const { return this->_window->isOpen(); }

void SfmlModule::destructor() { delete this; }

void SfmlModule::renderTextEntity(AEntity &) const {}

void SfmlModule::renderGameEntity(AEntity &) const {}

void SfmlModule::matchInputs(Events &inputs, sf::Keyboard::Key key) {
  switch (key) {
    case sf::Keyboard::Right:
      inputs.keys.push_back(RIGHT);
      break;
    case sf::Keyboard::Left:
      inputs.keys.push_back(LEFT);
      break;
    case sf::Keyboard::Down:
      inputs.keys.push_back(DOWN);
      break;
    case sf::Keyboard::Up:
      inputs.keys.push_back(UP);
      break;
    case sf::Keyboard::Escape:
      inputs.keys.push_back(ESCAPE);
      break;
    case sf::Keyboard::Space:
      inputs.keys.push_back(SPACE);
      break;
    case sf::Keyboard::BackSpace:
      inputs.keys.push_back(BACK);
      break;
    case sf::Keyboard::F1:
      inputs.keys.push_back(ONE);
      break;
    case sf::Keyboard::F2:
      inputs.keys.push_back(TWO);
      break;
    case sf::Keyboard::F3:
      inputs.keys.push_back(THREE);
      break;
    case sf::Keyboard::F4:
      inputs.keys.push_back(FOUR);
      break;
    case sf::Keyboard::F5:
      inputs.keys.push_back(FIVE);
      break;
    default:
      break;
  }
}
