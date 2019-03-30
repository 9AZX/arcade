/*
** EPITECH PROJECT, 2019
** Choose
** File description:
** Choose class header.
** @Author: Cédric Hennequin
** @Date:   30-03-2019 18:21:46
** @Last Modified by:   Cédric Hennequin
** @Last Modified time: 30-03-2019 20:11:47
*/

#ifndef	CHOOSE_HPP_
#define	CHOOSE_HPP_

#include <ncurses.h>
#include "Application.hpp"

class Choose
{
public:
	Choose() = default;
	~Choose() = default;

public:
	void launchLibraries(Application &app);
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
