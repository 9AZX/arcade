/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Application
*/

#include "Application.hpp"
#include <cstring>
#include <iostream>
#include "Choose.hpp"
#include "Exception.hpp"

static const struct libs libraries[] = {
    {Library::LIB_GAME, "pacman", LIB_GAME_PACMAN},
    {Library::LIB_GAME, "nibbler", LIB_GAME_NIBBLER},
    {Library::LIB_GRAPHIC, "ncurses", LIB_GRAPHIC_NCURSES},
    {Library::LIB_GRAPHIC, "sfml", LIB_GRAPHIC_SFML}};

void Application::init(const int argc, const char **argv) {
  if (argc != 2) {
    throw Exception(ERR_USAGE);
  }
  try {
    std::unique_ptr<Choose> choose(new Choose);
    this->_graphic = std::make_unique<Library>(argv[1]);
    this->_graphic->open();
    this->open_graphical_library();
    choose->launchLibraries(*this, argv[1]);
    if (this->_lib != -1) {
      this->_graphic = std::make_unique<Library>(libraries[this->_lib].path);
      this->_graphic->open();
      this->open_graphical_library();
    }
    if (this->_choose != -1) {
      this->_graphClass = (IDisplayModule *)(*this->fptr_graphic)();
      this->_game = std::make_unique<Library>(libraries[this->_choose].path);
      this->_game->open();
      this->open_game_library();
      this->_gameClass = (IGameModule *)(*this->fptr_game)(this);
      this->_gameClass->play();
    }
  } catch (...) {
    throw;
  }
}

void Application::stop() {
  try {
    if (this->_game) {
      this->_gameClass->destructor();
      this->_game->close();
    }
    if (this->_graphic) {
      if (this->_choose != -1) this->_graphClass->destructor();
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
      this->_gameClass->destructor();
      this->_game->openNew(path);
      this->open_game_library();
      this->_gameClass = (IGameModule *)(*this->fptr_game)(this);
    }
  } catch (...) {
    throw;
  }
}

void Application::storeGameEntity(AEntity *entity) {
  this->_entities.push_back(std::unique_ptr<AEntity>(entity));
}

AEntity &Application::getEntity(int name) {
  std::vector<std::unique_ptr<AEntity>>::iterator i = std::find_if(
      this->_entities.begin(), this->_entities.end(),
      [&name](std::unique_ptr<AEntity> &n) { return name == n->id; });
  if (i == this->_entities.end()) throw;
  return *this->_entities.at(std::distance(this->_entities.begin(), i)).get();
}

Events Application::getInputs() {
  Events input = this->_graphClass->getInputs();
  auto inputs = input.keys;

  if (std::find(inputs.begin(), inputs.end(), ONE) != inputs.end()) {
    if (strcmp(this->_graphClass->getLibraryName().c_str(), "ncurses") == 0) {
      this->switchLib(Library::LIB_GRAPHIC, libraries[3].path);
    } else if (strcmp(this->_graphClass->getLibraryName().c_str(), "sfml") ==
               0) {
      this->switchLib(Library::LIB_GRAPHIC, libraries[2].path);
    }
  } else if (std::find(inputs.begin(), inputs.end(), TWO) != inputs.end()) {
    if (strcmp(this->_graphClass->getLibraryName().c_str(), "ncurses") == 0) {
      this->switchLib(Library::LIB_GRAPHIC, libraries[3].path);
    } else if (strcmp(this->_graphClass->getLibraryName().c_str(), "sfml") ==
               0) {
      this->switchLib(Library::LIB_GRAPHIC, libraries[2].path);
    }
  } else if (std::find(inputs.begin(), inputs.end(), THREE) != inputs.end()) {
    if (strcmp(this->_gameClass->getLibraryName().c_str(), "pacman") == 0) {
      this->switchLib(Library::LIB_GAME, libraries[1].path);
    } else if (strcmp(this->_gameClass->getLibraryName().c_str(), "nibbler") ==
               0) {
      this->switchLib(Library::LIB_GAME, libraries[0].path);
    }
  } else if (std::find(inputs.begin(), inputs.end(), FOUR) != inputs.end()) {
    if (strcmp(this->_gameClass->getLibraryName().c_str(), "pacman") == 0) {
      this->switchLib(Library::LIB_GAME, libraries[1].path);
    } else if (strcmp(this->_gameClass->getLibraryName().c_str(), "nibbler") ==
               0) {
      this->switchLib(Library::LIB_GAME, libraries[0].path);
    }
  }
  return input;
}

void Application::renderAll() {
  this->_graphClass->startMusic(this->_gameClass->getMusicPath());
  this->_graphClass->displayMap(this->_gameClass->getMap());
  std::for_each(this->_entities.begin(), this->_entities.end(),
                [&, this](std::unique_ptr<AEntity> &n) {
                  if (n->isAlive) _graphClass->displayEntity(*n);
                });
  this->_graphClass->refreshWindow();
}

void Application::setMap(GameMap &) {}

bool Application::isOpen() const { return this->_graphClass->isOpen(); }