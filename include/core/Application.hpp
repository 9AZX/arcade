/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** Class Application
*/

#ifndef	APPLICATION_HPP_
#define	APPLICATION_HPP_

#include <string>

class Application
{
public:
		Application() = default;
		~Application() = default;

public:
	void init(const int argc, const char **argv);
};

#endif	/* !APPLICATION_HPP_ */
