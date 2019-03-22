/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Class Application
*/

#ifndef	APPLICATION_HPP_
#define	APPLICATION_HPP_

#include <string>
#include <memory>
#include "Library.hpp"

#define	ENTRY_POINT_GAME	"EntryGame"
#define	ENTRY_POINT_GRAPHIC	"EntryGraph"

class Application
{
public:
	Application() = default;
	~Application() = default;

public:
	void init(const int argc, const char **argv);
	void stop();
	void open_graphical_library();
	void open_game_library();
	void *_gameClass = nullptr;
	void *_graphClass = nullptr;

protected:
	std::unique_ptr<Library> _game = nullptr;
	std::unique_ptr<Library> _graphic = nullptr;
	void *(*fptr_game)() = nullptr;
	void *(*fptr_graphic)() = nullptr;
};

#endif	/* !APPLICATION_HPP_ */
