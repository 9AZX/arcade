/*
** EPITECH PROJECT, 2019
** Arcade
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include "Map.hpp"
#include "memory"

class IGameModule
{
  public:
	IGameModule();
	~IGameModule();

  public:
	virtual void play() = 0;
	virtual void pause() = 0;
	virtual void endGame() = 0;
	virtual std::unique_ptr<Map> getMap() = 0;
	virtual int getScore() = 0;

  private:
	int _score = -1;
};

#endif /* !IGAMEMODULE_HPP_ */
