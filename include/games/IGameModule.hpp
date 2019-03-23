/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IGameModule
*/

#ifndef	IGAMEMODULE_HPP_
#define	IGAMEMODULE_HPP_

#include "GameMap.hpp"
#include "Player.hpp"
#include <memory>

class IGameModule
{
public:
	virtual ~IGameModule() = default;

public:
	virtual void play() = 0;
	virtual void pauseMenu() = 0;
	virtual void endGame() = 0;
	virtual const GameMap &getMap() const noexcept = 0;
	virtual long getScore() const = 0;

private:
	long _score = -1;
};

#endif	/* !IGAMEMODULE_HPP_ */
