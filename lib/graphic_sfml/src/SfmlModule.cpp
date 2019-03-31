/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SfmlModule
*/

#include "SfmlModule.hpp"
#include <unistd.h>

SfmlModule::SfmlModule() {
  this->_window = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(SFML_WINDOW_HEIGHT, SFML_WINDOW_WIDTH), SFML_WINDOW_NAME);
  this->_window->setFramerateLimit(SFML_WINDOW_FRAMERATE);
  this->_window->setKeyRepeatEnabled(false);
  this->_window->clear();
}

SfmlModule::~SfmlModule() {}

const std::string &SfmlModule::getLibraryName() const noexcept {
  return this->_name;
}

void SfmlModule::startMusic(std::string path) {
  sf::SoundBuffer soundBuffer;
  sf::Sound sound;

  if (!soundBuffer.loadFromFile(path)) std::cout << "Music failed" << std::endl;
  std::cout << "music..." << std::endl;
  sound.setBuffer(soundBuffer);
  sound.setLoop(true);
  sound.play();
}

void SfmlModule::initGraphics(GameMap &map) {
  sf::Texture wallTexture;
  sf::Sprite wallSprite;

  wallTexture.loadFromFile(map.blockProperties['#'].assetPath);
  wallSprite.setOrigin(16, 16);
  this->_sprites.insert({666, std::make_pair(wallSprite, wallTexture)});
  this->_sprites[666].first.setTexture(this->_sprites[666].second, true);
  this->_sprites[666].first.setColor(sf::Color::Blue);
}

void SfmlModule::initGameEntity(AEntity &tmp) {
  sf::Texture wallTexture;
  sf::Sprite wallSprite;
  GameEntity *entity = static_cast<GameEntity *>(&tmp);
  sf::IntRect r1(0, 0, 32, 32);

  wallTexture.loadFromFile(entity->assetPath);
  wallSprite.setOrigin(16, 16);
  this->_sprites.insert({entity->id, std::make_pair(wallSprite, wallTexture)});
  this->_sprites[entity->id].first.setTexture(this->_sprites[entity->id].second,
                                              true);
  this->_sprites[entity->id].first.setTextureRect(r1);
  // if (entity->id >= 201) {
  // entity->isMoving = true;
  //   entity->moveRandom = true;
  //   entity->setPos(std::pair<int, int>(9, 10));
  // }
}

Events SfmlModule::getInputs() {
  Events actual;

  this->_window->setKeyRepeatEnabled(false);
  while (this->_window->pollEvent(this->eventSFML)) {
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
  }
  return actual;
}

int SfmlModule::animateEntity(AEntity &entity) noexcept {
  sf::IntRect r1(0, 0, 32, 32);
  sf::IntRect r2(32, 0, 32, 32);
  sf::IntRect r3(64, 0, 32, 32);  // do declaration outside game loop

  if (entity.animIt < 6) {
    this->_sprites[entity.id].first.setTextureRect(r2);
  } else if (entity.animIt < 10) {
    this->_sprites[entity.id].first.setTextureRect(r3);
  } else if (entity.animIt < 16) {
    this->_sprites[entity.id].first.setTextureRect(r2);
  } else {
    this->_sprites[entity.id].first.setTextureRect(r1);
    entity.animIt = 0;
  }
  entity.animIt += 1;
  return entity.animIt;
}

void SfmlModule::smoothlyMove(AEntity &entity) {
  if (entity.animIt < 16) {
    if (entity.moveRight)
      this->_sprites[entity.id].first.move(2, 0);
    else if (entity.moveLeft)
      this->_sprites[entity.id].first.move(-2, 0);
    else if (entity.moveUp)
      this->_sprites[entity.id].first.move(0, -2);
    else if (entity.moveDown)
      this->_sprites[entity.id].first.move(0, 2);
  } else {
    entity.moveDown = false;
    entity.moveUp = false;
    entity.moveRight = false;
    entity.moveLeft = false;
    entity.isMoving = false;
  }
  if (entity.getAnimated()) {
    entity.animIt = this->animateEntity(entity);
  }
  return;
}

void SfmlModule::moveRandom(AEntity *entity) {
  srand((unsigned)time(NULL));
  int res = rand() % 4;
  if (res == 0)
    entity->moveRight = true;
  else if (res == 1)
    entity->moveLeft = true;
  else if (res == 2)
    entity->moveUp = true;
  else if (res == 3)
    entity->moveDown = true;
}

void SfmlModule::moveGhost(AEntity *entity) {
  std::pair<int, int> pos = entity->getPos();
  std::cout << pos.first << " " << pos.second << std::endl;
  if (entity->animIt < 16) {
    if (entity->moveRight) {
      // this->_sprites[201].first.setPosition(5, 5);
      entity->setPos(std::pair<int, int>(pos.first + 2, pos.second));
      entity->moveRight = false;
      // std::cout << "right" << std::endl;
    } else if (entity->moveLeft)
      this->_sprites[201].first.move(-2, 0);
    else if (entity->moveUp)
      this->_sprites[201].first.move(0, -2);
    else if (entity->moveDown)
      this->_sprites[201].first.move(0, 2);
  } else {
    entity->animIt = 0;
  }
}

bool SfmlModule::displayEntity(AEntity &entity) {
  std::unordered_map<int, std::pair<sf::Sprite, sf::Texture>>::iterator i =
      this->_sprites.find(entity.id);
  if (i == this->_sprites.end()) {
    this->initGameEntity(entity);
  }
  this->_sprites[entity.id].first.setRotation(entity.getRotation());
  if (entity.isMoving)
    this->smoothlyMove(entity);
  else
    this->_sprites[entity.id].first.setPosition(entity.getPos().first * 32,
                                                entity.getPos().second * 32);
  if (entity.id >= 201) {
    this->moveRandom(&entity);
    // this->moveGhost(&entity);
  }
  this->_window->draw(this->_sprites[entity.id].first);
  return true;
}

void SfmlModule::displayMap(GameMap map) {
  if (this->_sprites.empty()) {
    this->initGraphics(map);
  }
  for (int ith = 0; ith < map.height; ith++) {
    for (int itl = 0; itl < map.width; itl++) {
      if (map.grid[ith][itl] == '#') {
        this->_sprites[666].first.setPosition(itl * 32 + 32, ith * 32 + 32);
        this->_window->draw(this->_sprites[666].first);
      }
    }
  }
}

bool SfmlModule::isOpen() const {
  if (this->_window) {
    return this->_window->isOpen();
  }
  return false;
}

void SfmlModule::destructor() { delete this; }

bool SfmlModule::renderTextEntity(AEntity &) const { return true; }

bool SfmlModule::renderGameEntity(AEntity &) const { return false; }

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
      this->_window->close();
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

void SfmlModule::refreshWindow() const noexcept {
  this->_window->display();
  this->_window->clear();
}