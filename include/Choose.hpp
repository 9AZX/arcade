/*
** EPITECH PROJECT, 2019
** Choose
** File description:
** Choose class header.
** @Author: Cédric Hennequin
** @Date:   30-03-2019 18:21:46
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 31-03-2019 01:15:33
*/

#ifndef	CHOOSE_HPP_
#define	CHOOSE_HPP_

#include <string>
#include <ncurses.h>
#include <SFML/Window.hpp>
#include "Application.hpp"

class Choose
{
public:
	Choose() = default;
	~Choose() = default;
	void launchLibraries(Application &app, const std::string &path);

public:
	void sfml_init(Application &app);

public:
	void ncurses_init(Application &app);
	void print_name() noexcept;
	void print_menu(Application &app) noexcept;
	void print_game_pacman(int &interval) noexcept;
	void print_game_nibbler(int &interval) noexcept;
	int getKey() const noexcept;
	void setLoop(const bool status) noexcept;
	void setKey(const int key) noexcept;

private:
	WINDOW *_windowLeft = nullptr;
	WINDOW *_windowRight = nullptr;
	bool _loop = true;
	int _key = 0;
};

#endif	/* !CHOOSE_HPP_ */
