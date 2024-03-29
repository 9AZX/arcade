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
  srand((unsigned)time(NULL));
  if (!_font.loadFromFile("./assets/retro.ttf")) {
    throw;
  }
}

SfmlModule::~SfmlModule() {}

const std::string &SfmlModule::getLibraryName() const noexcept {
  return this->_name;
}

void SfmlModule::startMusic(std::string path) {
  if (this->_isPlayingMusic) return;
  this->_music.openFromFile(path);
  this->_music.setLoop(true);
  this->_music.play();
  this->_isPlayingMusic = true;
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
}

void SfmlModule::initTextEntity(AEntity &tmp) {
  sf::Text text;
  TextEntity *entity = static_cast<TextEntity *>(&tmp);

  text.setFont(_font);
  text.setString(entity->getText());
  text.setFillColor(sf::Color::White);
  text.setCharacterSize(18);
  this->_texts.insert({entity->id, text});
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
  int res = rand() % 4;
  res = (res + entity->id) % 4;
  std::pair<int, int> pos = entity->getPos();

  entity->moveRight = false;
  entity->moveLeft = false;
  entity->moveUp = false;
  entity->moveDown = false;
  if (res == 0 && pos.first < 18)
    entity->moveRight = true;
  else if (res == 1 && pos.first > 2)
    entity->moveLeft = true;
  else if (res == 2 && pos.second > 2)
    entity->moveUp = true;
  else if (res == 3 && pos.second < 18)
    entity->moveDown = true;
}

void SfmlModule::moveGhost(AEntity *entity) {
  std::pair<int, int> pos = entity->getPos();
  if (entity->animIt == 16) {
    if (entity->moveRight) {
      entity->setPos(std::pair<int, int>(pos.first + 1, pos.second));
      entity->moveRight = false;
      entity->animIt = 16;

    } else if (entity->moveLeft) {
      entity->setPos(std::pair<int, int>(pos.first - 1, pos.second));
      entity->moveLeft = false;
      entity->animIt = 16;

      this->_sprites[201].first.move(-1, 0);
    } else if (entity->moveUp) {
      entity->moveUp = false;
      entity->animIt = 16;

      entity->setPos(std::pair<int, int>(pos.first, pos.second - 1));
      this->_sprites[201].first.move(0, -1);
    } else if (entity->moveDown) {
      entity->moveDown = false;
      entity->animIt = 16;

      entity->setPos(std::pair<int, int>(pos.first, pos.second + 1));
      this->_sprites[201].first.move(0, 1);
    }
    entity->animIt = 0;
  } else {
    entity->animIt += 1;
  }
}

bool SfmlModule::displayEntity(AEntity &entity) {
  switch (entity.getType()) {
    case AEntity::GAME:
      return renderGameEntity(entity);
      break;
    case AEntity::TEXT:
      return renderTextEntity(entity);
      break;
    default:
      return false;
  }
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

bool SfmlModule::renderTextEntity(AEntity &entity) {
  auto i = this->_texts.find(entity.id);
  const auto textEntity = static_cast<TextEntity *>(&entity);

  if (i == this->_texts.end()) {
    initTextEntity(entity);
  } else if (textEntity->getText() != this->_texts[entity.id].getString()) {
    this->_texts[entity.id].setString((textEntity->getText()));
  }
  this->_texts[entity.id].setPosition(entity.getPos().first * 32,
                                      entity.getPos().second * 32);
  this->_window->draw(this->_texts[entity.id]);
  return true;
}

bool SfmlModule::renderGameEntity(AEntity &entity) {
  auto i = this->_sprites.find(entity.id);
  if (i == this->_sprites.end()) {
    this->initGameEntity(entity);
  }
  this->_sprites[entity.id].first.setRotation(entity.getRotation());
  if (entity.isMoving)
    this->smoothlyMove(entity);
  else
    this->_sprites[entity.id].first.setPosition(entity.getPos().first * 32,
                                                entity.getPos().second * 32);
  if (entity.id >= 401 && entity.id <= 404) {
    this->moveRandom(&entity);
    this->moveGhost(&entity);
  }
  this->_window->draw(this->_sprites[entity.id].first);
  return true;
}

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