/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Application
*/

#include "Application.hpp"
#include "Exception.hpp"

void Application::init(const int argc, const char **argv)
{
	if (argc != 2) {
		throw Exception(ERR_USAGE);
	}
	try {
		this->_graphic = std::make_unique<Library>(argv[1]);
		this->_graphic->open();
		this->fptr_graphic = (void (*)()) this->_graphic->sym("EntryGame");
		(*this->fptr_graphic)();
	}
	catch (...) {
		throw;
	}
}

void Application::stop()
{
	try {
		//this->_game->close();
		//this->_graphic->close();
	}
	catch (...) {
		throw;
	}
}
