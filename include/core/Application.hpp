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

protected:
	std::unique_ptr<Library> _game = NULL;
	std::unique_ptr<Library> _graphic = NULL;
};

#endif	/* !APPLICATION_HPP_ */
