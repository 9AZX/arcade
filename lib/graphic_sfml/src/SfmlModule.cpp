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
#if defined(__linux__)
  this->_window->setFramerateLimit(SFML_WINDOW_FRAMERATE);
#endif
}

SfmlModule::~SfmlModule() {}

void SfmlModule::initGraphics(GameMap &map) {
  sf::Texture wallTexture;
  sf::Sprite wallSprite;

  wallTexture.loadFromFile(map.blockProperties['#'].assetPath);
  wallSprite.setOrigin(16, 16);
  this->_sprites.insert({"wall", std::make_pair(wallSprite, wallTexture)});
  this->_sprites["wall"].first.setTexture(this->_sprites["wall"].second, true);
  this->_sprites["wall"].first.setColor(sf::Color::Blue);
}

void SfmlModule::initGameEntity(AEntity &tmp) {
  sf::Texture wallTexture;
  sf::Sprite wallSprite;
  GameEntity *entity = static_cast<GameEntity *>(&tmp);

  wallTexture.loadFromFile(entity->assetPath);
  wallSprite.setOrigin(16, 16);
  this->_sprites.insert({entity->id, std::make_pair(wallSprite, wallTexture)});
  this->_sprites[entity->id].first.setTexture(this->_sprites[entity->id].second,
                                              true);
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

int SfmlModule::animateEntity(AEntity &entity) noexcept {
  sf::IntRect r1(0, 0, 32, 32);
  sf::IntRect r2(32, 0, 32, 32);
  sf::IntRect r3(64, 0, 32, 32);

  if (entity.animIt < 16) {
    this->_sprites[entity.id].first.setTextureRect(r2);
  } else if (entity.animIt < 32) {
    this->_sprites[entity.id].first.setTextureRect(r3);
  } else {
    this->_sprites[entity.id].first.setTextureRect(r1);
    entity.animIt = 0;
  }
  entity.animIt += 1;
  std::cout << entity.animIt << std::endl;
  return entity.animIt;
}

void SfmlModule::displayEntity(AEntity &entity) {
  std::unordered_map<std::string, std::pair<sf::Sprite, sf::Texture>>::iterator
      i = this->_sprites.find(entity.id);
  if (i == this->_sprites.end()) {
    this->initGameEntity(entity);
  }
  this->_sprites[entity.id].first.setPosition(entity.getPos().first * 32,
                                              entity.getPos().second * 32);
  if (entity.isAnimated && entity.id == "Player") {
    entity.animIt = this->animateEntity(entity);
    // this->_sprites[entity.id].first.setTextureRect(sf::IntRect(32, 0, 32,
    // 32));
  }
  this->_window->draw(this->_sprites[entity.id].first);
  this->_window->display();
}

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
