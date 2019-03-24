/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Application
*/

#include "Application.hpp"
#include "Exception.hpp"

static const struct libs libraries[] = {
    {Library::LIB_GAME, "nibbler", "./games/lib_arcade_nibbler.so"},
    {Library::LIB_GAME, "pacman", "./games/lib_arcade_pacman.so"},
    {Library::LIB_GRAPHIC, "ncurses", "./lib/lib_arcade_ncurses.so"},
    {Library::LIB_GRAPHIC, "sfml", "./lib/lib_arcade_sfml.so"}};

void Application::init(const int argc, const char **argv) {
  if (argc < 2) {
    throw Exception(ERR_USAGE);
  }
  try {
    this->_graphic = std::make_unique<Library>(argv[1]);
    this->_graphic->open();
    this->open_graphical_library();
    this->_graphClass = (IDisplayModule *)(*this->fptr_graphic)();
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

void Application::storeGameEntity(AEntity *entity) {}

AEntity &Application::getEntity(std::string name) {}

std::vector<enum gameInputs> Application::getInputs() {
  std::vector<enum gameInputs> mdr;

  return mdr;
}

void Application::renderAll() {
  this->_graphClass->displayMap(this->_gameClass->getMap());
}

void Application::setMap(GameMap &map) {}
