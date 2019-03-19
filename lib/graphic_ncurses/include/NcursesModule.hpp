/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NcursesModule
*/

#ifndef	NCURSESMODULE_HPP_
#define	NCURSESMODULE_HPP_

#include "IDisplayModule.hpp"
#include <ncurses.h>

class NcursesModule : public IDisplayModule
{
public:
	NcursesModule() = default;
	~NcursesModule() = default;

public:
	void initScreen() override;
	void print_map(Map) override;
};

#endif	/* !NCURSESMODULE_HPP_ */
