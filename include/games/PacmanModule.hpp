/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** PacmanModule
*/

#ifndef	PACMANMODULE_HPP_
#define	PACMANMODULE_HPP_

#include "IGameModule.hpp"

class PacmanModule : public IGameModule
{
public:
	PacmanModule() = default;
	~PacmanModule() = default;

public:
	void play();
};

#endif	/* !PACMANMODULE_HPP_ */
