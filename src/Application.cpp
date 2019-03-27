/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Application
*/

#include "Application.hpp"
#include <iostream>
#include "Exception.hpp"

static const struct libs libraries[] = {
    {Library::LIB_GAME, "nibbler", LIB_GAME_NIBBLER},
    {Library::LIB_GAME, "pacman", LIB_GAME_PACMAN},
    {Library::LIB_GRAPHIC, "ncurses", LIB_GRAPHIC_NCURSES},
    {Library::LIB_GRAPHIC, "sfml", LIB_GRAPHIC_SFML}};

void Application::init(const int argc, const char **argv) {
  if (argc < 2) {
    throw Exception(ERR_USAGE);
  }
  try {
    this->_graphic = std::make_unique<Library>(argv[1]);
    this->_graphic->open();
    this->open_graphical_library();
    this->_graphClass = (IDisplayModule *)(*this->fptr_graphic)();
    // this->switchLib(Library::LIB_GRAPHIC, libraries[3].path);
    this->_game = std::make_unique<Library>(argv[2]);
    this->_game->open();
    this->open_game_library();
    this->_gameClass = (IGameModule *)(*this->fptr_game)(this);
    this->_gameClass->play();
  } catch (...) {
    throw;
  }
}

void Application::stop() {
  try {
    if (this->_game) {
      // this->_gameClass->destructor();
      this->_game->close();
    }
    if (this->_graphic) {
      this->_graphClass->destructor();
      this->_graphic->close();
    }
  } catch (...) {
    throw;
  }
}

void Application::open_graphical_library() {
  std::string error = "";

  try {
    this->fptr_graphic =
        reinterpret_cast<void *(*)()>(this->_graphic->sym(ENTRY_POINT_GRAPHIC));
  } catch (...) {
    error += "Library (";
    error += this->_graphic->get_path();
    error += ") isn't a graphical library.";
    throw Exception(error);
  }
}

void Application::open_game_library() {
  std::string error = "";

  try {
    this->fptr_game =
        reinterpret_cast<void *(*)(void *)>(this->_game->sym(ENTRY_POINT_GAME));
  } catch (...) {
    error += "Library (";
    error += this->_game->get_path();
    error += ") isn't a game library.";
    throw Exception(error);
  }
}

void Application::switchLib(const int type, const std::string &path) {
  try {
    if (type == Library::LIB_GRAPHIC && this->_graphic) {
      this->_graphClass->destructor();
      this->_graphic->openNew(path);
      this->open_graphical_library();
      this->_graphClass = (IDisplayModule *)(*this->fptr_graphic)();
    } else if (type == Library::LIB_GAME && this->_game) {
      // this->_gameClass->destructor();
      this->_game->openNew(path);
      this->open_game_library();
      this->_gameClass = (IGameModule *)(*this->fptr_game)(this);
    }
  } catch (...) {
    throw;
  }
}

void Application::storeGameEntity(AEntity *entity) {
  this->_entities.push_back(*entity);
}

AEntity &Application::getEntity(std::string name) {
  std::vector<AEntity>::iterator i =
      std::find_if(this->_entities.begin(), this->_entities.end(),
                   [&name](AEntity &n) { return name == n.id; });
  if (i == this->_entities.end()) throw;
  return this->_entities.at(std::distance(this->_entities.begin(), i));
}

Events Application::getInputs() { return this->_graphClass->getInputs(); }

void Application::renderAll() {
  this->_graphClass->displayMap(this->_gameClass->getMap());
  std::for_each(this->_entities.begin(), this->_entities.end(),
                [&, this](AEntity &n) { _graphClass->displayEntity(n); });
}

void Application::setMap(GameMap &map) {}

bool Application::isOpen() const { return this->_graphClass->isOpen(); }