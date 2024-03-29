/*
** EPITECH PROJECT, 2019
** Choose
** File description:
** Choose class header.
** @Author: Cédric Hennequin
** @Date:   30-03-2019 18:21:46
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 31-03-2019 22:17:42
*/

#ifndef	CHOOSE_HPP_
#define	CHOOSE_HPP_

#include <string>
#include <ncurses.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Application.hpp"

class Choose
{
public:
	Choose() = default;
	~Choose() = default;
	void launchLibraries(Application &app, const std::string &path);
	void init(Application &app, const std::string &defaultInit);

public:
	void sdl2_init(Application &app, std::string &lib);

public:
	void sfml_init(Application &app, std::string &lib);

public:
	void ncurses_init(Application &app, std::string &lib) noexcept;
	void print_name() noexcept;
	void print_menu(Application &app, std::string &lib) noexcept;
	void print_game_pacman(int &interval) noexcept;
	void print_game_nibbler(int &interval) noexcept;
	int getKey() const noexcept;
	void setLoop(const bool status) noexcept;
	void setKey(const int key) noexcept;

public:
	bool _global_loop = true;

private:
	WINDOW *_windowLeft = nullptr;
	WINDOW *_windowRight = nullptr;
	bool _loop = true;
	int _key = 0;
};

#endif	/* !CHOOSE_HPP_ */
