/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Application
*/

#include "Application.hpp"
#include "Exception.hpp"
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"

void Application::init(const int argc, const char** argv)
{
    if (argc < 2) {
        throw Exception(ERR_USAGE);
    }
    try {
        this->_graphic = std::make_unique<Library>(argv[1]);
        this->_graphic->open();
        this->open_graphical_library();
        this->_graphClass = (*this->fptr_graphic)();

        this->_game = std::make_unique<Library>(argv[2]);
        this->_game->open();
        this->open_game_library();
        this->_gameClass = (*this->fptr_game)();
    } catch (...) {
        throw;
    }
}

void Application::stop()
{
    try {
        if (this->_game) {
            this->_game->close();
        }
        if (this->_graphic) {
            this->_graphic->close();
        }
    } catch (...) {
        throw;
    }
}

void Application::open_graphical_library()
{
    std::string error = "";

    try {
        this->fptr_graphic = reinterpret_cast<void* (*)()>(
            this->_graphic->sym(ENTRY_POINT_GRAPHIC));
    } catch (...) {
        error += "Library (";
        error += this->_graphic->get_path();
        error += ") isn't a graphical library.";
        throw Exception(error);
    }
}

void Application::open_game_library()
{
    std::string error = "";

    try {
        this->fptr_game = reinterpret_cast<void* (*)()>(
            this->_game->sym(ENTRY_POINT_GAME));
    } catch (...) {
        error += "Library (";
        error += this->_game->get_path();
        error += ") isn't a game library.";
        throw Exception(error);
    }
}

void Application::storeGameEntity(AEntity* entity)
{
}

AEntity& Application::getEntity(std::string name)
{
}

std::vector<enum gameInputs> Application::getInputs()
{
    std::vector<enum gameInputs> mdr;
    return mdr;
}

void Application::renderAll()
{
}

void Application::setMap(GameMap& map)
{
}
