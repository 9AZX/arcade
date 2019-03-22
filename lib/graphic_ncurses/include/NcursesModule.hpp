/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** NcursesModule
*/

#ifndef	NCURSESMODULE_HPP_
#define	NCURSESMODULE_HPP_

#include "IDisplayModule.hpp"
#include "IRender.hpp"
#include <ncurses.h>
#include <vector>
#include <memory>

class NcursesModule : public IDisplayModule, public IRender
{
public:
	NcursesModule();
	~NcursesModule();

public:
	std::vector<enum gameInputs> getInputs() final;
	void displayEntity(AEntity &) final;
	void displayMap() final;
	void renderTextEntity(AEntity &) const final;
	void renderGameEntity(AEntity &) const final;

private:
	void matchInputs(std::vector<enum gameInputs> &inputs, int key);
};

#endif	/* !NCURSESMODULE_HPP_ */
