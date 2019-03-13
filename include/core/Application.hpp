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

class Application
{
public:
		Application() = default;
		~Application() = default;

public:
	void init(const int argc, const char **argv);
	void stop();

protected:
	std::unique_ptr<Library> _game = nullptr;
	std::unique_ptr<Library> _graphic = nullptr;
	void (*fptr_game)() = nullptr;
	void (*fptr_graphic)() = nullptr;
};

typedef	void (*fptr_game)(void);

#endif	/* !APPLICATION_HPP_ */
